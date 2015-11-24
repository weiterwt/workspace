#ifndef MYAVLTREE_H
#define MYAVLTREE_H

#include <iostream>
using std::cout;
using std::endl;

//AVL树的实现
template <typename Object>
class MyAvlTree
{
	private:
		struct BinaryNode
		{
			Object element;
			BinaryNode *left;
			BinaryNode *right;
			int height;  //用来记录每个结点的高度，叶子结点的高度为0，空树的高度为-1
			BinaryNode(const Object &_element, BinaryNode *_left, BinaryNode *_right, int _height = 0)
				: element(_element), left(_left), right(_right), height(_height) { }
		};
		BinaryNode *root;
	public:
		//构造函数，很简单，只需要将root设置为空即可，相当于一棵空树
		MyAvlTree() : root(NULL) { }
		//析构函数，调用MakeEmpty()释放结点
		~MyAvlTree()
		{
			MakeEmpty();
		}
		//复制构造函数，利用operator=实现
		MyAvlTree(const MyAvlTree &other)
		{
			root = other.root;
		}
		//赋值操作符operator=的实现，首先相同性检查，然后释放*this原有的元素，在复制
		const MyAvlTree &operator= (const MyAvlTree &rhs)
		{
			if (this != &rhs)
			{
				MakeEmpty();
				root = clone(rhs.root);
			}
			return *this;
		}
		//检测树是否包含元素e
		bool contains(const Object &e) const
		{
			return contains(e, root);
		}
		//insert操作实现，调用insert(e,root)
		void insert(const Object &e)
		{
			if (contains(e))
				return ;
			insert(e, root);
		}
		//查找树中的最大值
		const Object &FindMax() const
		{
			BinaryNode *t = FindMax(root);
			if (t != NULL)
				return t->element;
			else
				return NULL;
		}
		//查找树中的最小值
		const Object &FindMin() const
		{
			BinaryNode *t = FindMin(root);
			return t == NULL ? NULL : t->element;
		}
		bool empty() const
		{
			return root == NULL;
		}
		//输出二叉查找树
		void PrintTree() const
		{
			if (empty())
				cout << "This tree is empty!" << endl;
			else
				PrintTree(root);
		}
		void MakeEmpty()
		{
			MakeEmpty(root);
		}
		void remove(const Object &e)
		{
			remove(e, root);
		}
	private:
		//判断两数中的最大值
		int max(int a, int b)
		{
			return a > b ? a : b;
		}
		//获取结点当前的高度
		int Height(BinaryNode *t) const
		{
			return t == NULL ? -1 : t->height;
		}
	    //insert操作实现，注意在此过程中进行旋转维持二叉查找树 
		void insert(const Object &e, BinaryNode* &t)
		{
			if (t == NULL)
				t = new BinaryNode(e, NULL, NULL);
			else if (e < t->element)
			{
				insert(e, t->left);
				if (Height(t->left) - Height(t->right) == 2)  //比较当前结点的左子树和右子树的高度差,如果等于2，则要进行旋转
				{
					if (e < t->left->element)   //左-左插入的情况
						RotateWithLeftChild(t);
					else
						DoubleWithLeftChild(t);
				}
			}
			else if (t->element < e)
			{
				insert(e, t->right);
				if (Height(t->right) - Height(t->left) == 2)
				{
					if (t->right->element < e)   //右-右插入的情况
						RotateWithRightChild(t);
					else
						DoubleWithRightChild(t);
				}
			}
			else
				;
			//这里这样写的话，要记住处理插入元素已在二叉树中的情况
			t->height = max(Height(t->left), Height(t->right)) + 1;  //一定要更新相关节点的高度信息
		}
		//实现单旋转，一定记住旋转后子树的根的改变，如果不更新那么就访问不到旋转后的根结点了
		void RotateWithLeftChild(BinaryNode* &t)
		{
			BinaryNode *p = t->left;
			t->left = p->right;
			p->right = t;
			t->height = max(Height(t->left), Height(t->right)) + 1;
			p->height = max(Height(t->left), t->height) + 1;
			t = p;
		}
		void RotateWithRightChild(BinaryNode* &t)
		{
			BinaryNode *p = t->right;
			t->right = p->left;
			p->left = t;
			t->height = max(Height(t->left), Height(t->right)) + 1;
			p->height = max(t->height, Height(t->right)) + 1;
			t = p;
		}
		//双旋转实现
		void DoubleWithLeftChild(BinaryNode* &t)
		{
			RotateWithRightChild(t->left);
			RotateWithLeftChild(t);
		}
		void DoubleWithRightChild(BinaryNode* &t)
		{
			RotateWithLeftChild(t->right);
			RotateWithRightChild(t);
		}
		//检测是否包含元素e
		bool contains(const Object &e, BinaryNode *t) const
		{
			if (t == NULL)
				return false;
			else if (e < t->element)
				contains(e, t->left);
			else if (t->element < e)
				contains(e, t->right);
			else
				return true;
		}
		BinaryNode *FindMax(BinaryNode *t) const
		{
			if (t != NULL)
			{
				while (t->right != NULL)
					t = t->right;
			}
			return t;
		}
		BinaryNode *FindMin(BinaryNode *t) const
		{
			if (t == NULL)
				return NULL;
			if (t->left == NULL)
				return t;
			return FindMin(t->left);
		}
		//中序遍历二叉查找树
		void PrintTree(BinaryNode *t) const
		{
			if (t == NULL)
				return ;
			PrintTree(t->left);
			cout << t->element << " ";
			PrintTree(t->right);
		}
		//释放所有的结点
		void MakeEmpty(BinaryNode* &t)
		{
			if (t != NULL)
			{
				MakeEmpty(t->left);
				MakeEmpty(t->right);
				delete t;
			}
			t = NULL;
		}
		//复制一棵树的每一个节点
		BinaryNode *clone(BinaryNode *t) const
		{
			if (t == NULL)
				return NULL;
			return new BinaryNode(t->element, clone(t->left), clone(t->right));
		}
		void remove(const Object &e, BinaryNode* &t)
		{
		}
};

#endif

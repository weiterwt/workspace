#ifndef BINARYSEARCHTREE_H
#define BINARYSEARCHTREE_H

/**
  二叉查找树：任意一个结点的左儿子小于该结点的值，右儿子大于该结点的值
  基本操作：插入、查找、删除
**/
template <typename Object>
class BinarySearchTree
{
	private:
		struct BinaryNode  //结点
		{
			Object element;
			BinaryNode *left;
			BinaryNode *right;
			BinaryNode(const Object _element = Object(), BinaryNode *_left = NULL, BinaryNode *_right = NULL) :
				element(_element), left(_left), right(_right) { }
		};
		BinaryNode *root;
	public:
		BinarySearchTree() : root(NULL) { }
		~BinarySearchTree() 
		{
			MakeEmpty();
		}
		//复制构造函数实现
		BinarySearchTree(const BinarySearchTree &other)
		{
			root = other.root;
		}
		//赋值操作符实现
		const BinarySearchTree &operator= (const BinarySearchTree &rhs)
		{
			if (this != &rhs)
			{
				MakeEmpty();
				root = clone(rhs.root);
			}
			return *this;
		}
		void insert(const Object &e)
		{
			insert(e, root);
		}
		void remove(const Object &e)
		{
			remove(e, root);
		}
		const Object &FindMin() const
		{
			return FindMin(root);
		}
		const Object &FindMax() const
		{
			return FindMax(root);
		}
		//释放树的所有结点
		void MakeEmpty()
		{
			MakeEmpty(root);
		}
		//树空测试
		bool empty() const
		{
			return root == NULL;
		}
	private:
		void insert(const Object &e, BinaryNode* &t)
		{
			if (t == NULL)
				t = new BinaryNode(e);    //创建结点
			else if (e < t->element)
				insert(e, t->left);
			else if (t->element < e)
				insert(e, t->right);
			else
				;     //如果元素已存在于树中，则什么也不做
		}
		void remove(const Object &e, BinaryNode* &t)
		{
			if (t == NULL)
				return ;
			if (e < t->element)
				remove(e, t->left);
			else if (t->element < e)
				remove(e, t->right);
			else if (t->left != NULL && t->right != NULL)
			{
				t->element = FindMin(t->right); //找到右子树中的最小值，替换掉这个元素，再递归地在右子树中删除该元素
				remove(t->element, t->right);
			}
			else
			{
				BinaryNode *old_node = t;      //将当前结点保存下来，然后将t（按引用传递的指针）改为指向它现在所指向的下一个节点
				t = (t->left != NULL) ? t->left : t->right;
				delete old_node;   //删除结点，释放空间
			}
		}
		const Object &FindMin(BinaryNode *t) const //例程中返回的是结点的指针，如果直接返回结点的元素，是否可行？如果直接返回元素值，
		{                                          //一个问题就是在t为NULL时的返回不好处理，所以返回结点指针更好
			if (t == NULL)
				return NULL;
			while (t->left != NULL)
				t = t->left;
			return t->element;
		}
		const Object &FindMax(BinaryNode *t) const
		{
			if (t == NULL)
				return NULL;
			if (t->right == NULL)
				return t->element;
			return FindMax(t->right);
		}
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
		BinaryNode *clone(BinaryNode *t) const
		{
			if (t == NULL)
				return NULL;
			return new BinaryNode(t->element, clone(t->left), clone(t->right));
		}
};

#endif

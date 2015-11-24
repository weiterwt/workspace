#ifndef MYLIST_H
#define MYLIST_H
#include <iostream>

using std::endl;
using std::cout;

//实现MyList双向链表，带头、尾节点
template <typename Object>
class MyList
{
	private:
		//把节点信息定义为private内部类
		struct Node
		{
			Object element;
			Node *prev;  //前向指针
			Node *next;  //后向指针
			//Node的构造函数，实现对一个节点的初始化
			Node(const Object &e = Object(), Node *_prev = NULL, Node *_next = NULL) : \
				element(e), prev(_prev), next(_next) { }
		};
	public:
		//定义const_iterator iterator，iterator继承const_iterator，也就是，iterator可以转换为const_iterator，反之则不行
		class const_iterator
		{
		//	protected:
		//		Node *current;   //定义指向当前节点的指针，定义为protected是因为iterator也要使用这个变量，但是其他类不会用到
			public:
				const_iterator() : current(NULL) { }
				const Object &operator* () const  //定义解引用操作符，返回指针指向的值
				{
					return retrieve();
				}
				const_iterator &operator++()     //前置++实现
				{
					current = current->next;
					return *this;
				}
				const_iterator operator++ (int) //后置++实现
				{
					const_iterator old = *this;
					++(*this);
					return old;
				}
				bool operator== (const const_iterator &rhs) const //==操作符重载，只有当两个iterator指向同一个节点时，才是相等的？
				{
					return current == rhs.current;
				}
				bool operator!= (const const_iterator &rhs) const
				{
					return !(*this == rhs);
				}
			protected:
				Node *current;   //定义指向当前节点的指针，定义为protected是因为iterator也要使用这个变量，但是其他类不会用到
				Object &retrieve() const
				{
					return current->element;
				}
				const_iterator(Node *n) : current(n) { }
			friend class MyList<Object>;
		};
		class iterator:public const_iterator
		{
			public:
				iterator() { }  //什么都没有写，是因为它的成员变量已经在基类中初始化了
				Object &operator* ()
				{
					cout << "use no const operator*" << endl;
					return const_iterator::retrieve();
				}
				const Object &operator* () const   //什么时候调用上面那个，什么时候调用这个？
				{
					cout << "use const operator*" << endl;   //debug
					return const_iterator::operator*();
				}
				iterator &operator++ ()
				{
					const_iterator::current = const_iterator::current->next;
					return *this;
				}
				iterator operator++ (int)
				{
					iterator old = *this;
					++(*this);
					return old;
				}
			//protected:
				iterator(Node *n) : const_iterator(n) { }
			friend class MyList<Object>;
		};
	private:
		int the_size;
		Node *head;   //头节点
		Node *tail;   //尾节点
	public:
		//默认构造函数
		MyList()
		{
			init();
		}
		//析构函数
		~MyList()
		{
			//clear();      //释放节点信息
			delete head;  //释放头节点、尾节点，不能在clear中处理
			delete tail;
		}
		//复制构造函数
		MyList(const MyList &other)
		{
			init();
			*this = other;
		}
		//赋值操作符重载
		const MyList &operator= (const MyList &rhs)
		{
			if (this == &rhs)
				return *this;
			clear();
			for (const_iterator itr = rhs.begin(); itr != rhs.end(); ++itr)
				push_back(*itr);
			return *this;
		}
		iterator begin()
		{
			return iterator(head->next);
		}
		const_iterator begin() const
		{
			return const_iterator(head->next);
		}
		iterator end()
		{
			return iterator(tail);
		}
		const_iterator end() const
		{
			return const_iterator(tail);
		}
		int size() const
		{
			return the_size;
		}
		bool empty() const
		{
			return size() == 0;
		}
		void clear()
		{
			while (!empty())
				pop_front();
		}
		Object &front()
		{
			return *begin();
		}
		const Object &front() const
		{
			return *begin();
		}
		Object &back()
		{
			return *--end();
		}
		const Object &back() const
		{
			return *--end();
		}
		void push_front(const Object &e)
		{
			insert(begin(), e);
		}
		void push_back(const Object &e)
		{
			insert(end() ,e);
		}
		void pop_front()
		{
			erase(begin());
		}
		void pop_back()
		{
			erase(--end());
		}
		//插入操作
		iterator insert(iterator itr, const Object &e)
		{
			Node *p = itr.current;
			the_size++;
			return iterator(p->prev = p->prev->next = new Node(e, p->prev, p));
		}
		//删除元素，如何释放这个元素的空间？
		//因为创建这个元素时，是new的，所以这里可以直接删除
		iterator erase(iterator itr)
		{
			Node *p = itr.current;
			iterator return_value(p->next);
			p->prev->next = p->next;
			p->next->prev = p->prev;
			delete p;
			the_size--;
			return return_value;
		}
		iterator erase(iterator start, iterator end)
		{
			for (iterator itr = start; itr != end;)
				itr = erase(itr);
			return end;
		}
	private:
		void init()
		{
			the_size = 0;
			head = new Node;
			tail = new Node;
			head->next = tail;
			tail->prev = head;
		}
};

#endif











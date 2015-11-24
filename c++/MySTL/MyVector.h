#ifndef  MYVECTOR_H
#define  MYVECTOR_H

#include <iostream>
//MyVector类模板的实现
template <typename Object>
class MyVector
{
	private:
		int the_size;       //当前项的数目
		int the_capacity;   //MyVector的容量，当MyVector为空时，也有一个默认的容量大小
		Object *ptr;		//指针变量，存储数据
		enum {DEFAULT_CAPACITY = 16};   //默认的容量大小
	public:
		//为the_size的值提供默认实参：0，给形参提供默认实参只能提供一次，可在函数声明中给出
		MyVector(int _size = 0) : the_size(_size), the_capacity(_size + DEFAULT_CAPACITY)
		{
			ptr = new Object[_size + DEFAULT_CAPACITY];
		}
		//析构函数，释放分配的内存
		~MyVector()
		{
			delete [] ptr;
		}
		//复制构造函数，利用operator=实现
		MyVector(const MyVector &other) : ptr(NULL)
		{
			operator=(other);
		}
		//operator=函数，实现深复制操作
		const MyVector &operator= (const MyVector &rhs)
		{
			if (this != &rhs)   //自复制检测
			{
				delete [] ptr;     //释放ptr原有的内存空间
				the_size = rhs.the_size;
				the_capacity = rhs.the_capacity;
				ptr = new Object[capacity()];  //分配Capacity容量大小的内存空间
				for (int i = 0; i < size(); ++i) //将rhs中的数据复制到this中
					ptr[i] = rhs.ptr[i];
			}
			return *this;
		}
		//检测当前的对象是否为空，为空返回true
		bool empty() const
		{
			return size() == 0;
		}
		//改变MyVector的大小，一般情况是变大
		void resize(int new_size)
		{
			//如果new_size大于了当前的容量，则要先将容量扩大
			if (new_size > the_capacity)
				reserve(new_size * 2 + 1);
			the_size = new_size;   //更新数据项的数目
		}
		//改变MyVector容量的大小
		void reserve(int new_capacity)
		{
			//如果新的容量大小还小于了当前的容量大小，则不改变
			if (new_capacity <= the_capacity)
				return;
			//将以前的数据复制到新申请的内存中，再释放以前的内存
			Object *old_ptr = ptr;
			ptr = new Object[new_capacity];
			for (int i = 0; i < size(); ++i)
				ptr[i] = old_ptr[i];
			the_capacity = new_capacity;
			delete [] old_ptr;   //一定要删除以前的内存空间
		}
		//重载[]操作符，返回非const引用
		Object &operator[] (int index)
		{
			return ptr[index];
		}
		//返回const引用
		const Object &operator[] (int index) const
		{
			return ptr[index];
		}
		//返回当前元素的个数
		int size() const
		{
			return the_size;
		}
		//返回容量的大小
		int capacity() const
		{
			return the_capacity;
		}
		//push_back的实现，函数形参为const引用
		void push_back(const Object &element)
		{
			if (the_size == the_capacity)
				reserve(the_capacity * 2 + 1);
			ptr[the_size++] = element;
		}
		//pop_back实现，只需将the_size--就可以了
		void pop_back()
		{
			the_size--;
		}
		//back实现，返回最后一个元素的const引用
		const Object &back() const
		{
			return ptr[the_size - 1];
		}
		//iterator和const_iterator的实现，其实它们就是Object* 和const Object*
		//所以可以用typedef实现
		typedef Object * iterator;
		typedef const Object * const_iterator;
		//相关的begin和end函数实现
		iterator begin()
		{
			return &ptr[0];
		}
		const_iterator begin() const
		{
			return &ptr[0];
		}
		iterator end()
		{
			return &ptr[size()];
		}
		const_iterator end() const
		{
			return &ptr[size()];
		}
};





#endif

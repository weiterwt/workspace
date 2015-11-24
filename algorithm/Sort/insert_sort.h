#ifndef INSERT_SORT_H
#define INSERT_SORT_H
#include <vector>
using std::vector;
/*
**插入排序算法，将第一个元素看做有序的，然后将后面的元素依次插入
**将当前要插入的元素作为key，在已排序的序列中找出合适的位置
**算法时间复杂度为O(n2)
*/
//函数形参为数组的引用
template <typename Object>
void InsertSort(vector<Object> &a)
{
	for (int i = 1; i < a.size(); ++i)
	{
		Object key = a[i];
		int j;
		for (j = i -1; j >= 0 && a[j] > key; --j)
			a[j + 1] = a[j];
		a[j + 1] = key;
	}
}

#endif

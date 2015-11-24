#ifndef SELECT_SORT_H
#define SELECT_SORT_H

#include <vector>
using std::vector;

/*
 *选择排序（升序）：在剩下的数组元素中选择最小元素，放在现在的位置上
 *函数参数为数组的引用
 */
template <typename Object>
void SelectSort(vector<Object> &a)
{
	for (int i = 0; i < a.size() - 1 ; ++i)  //最后一个剩下的元素一定是最大的，所以不用选择出来
	{
		Object key = a[i];
		int j, k = i;
		for (j = i + 1; j < a.size(); ++j)
		{
			if (a[j] < key)
			{
				key = a[j];
				k = j;
			}
		}
		a[k] = a[i];
		a[i] = key;
	}
}

#endif

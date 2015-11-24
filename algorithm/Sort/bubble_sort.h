#ifndef BUBBLE_SORT_H
#define BUBBLE_SORT_H

#include <vector>
using std::vector;
/*
 *冒泡排序，从数组元素0开始，依次比较相邻元素的位置，如果错，则交换
 *每一趟中，到达最后的元素都是当前未排序中最大的
*/
template <typename Object>
void BubbleSort(vector<Object> &a)
{
	for (int i = 0; i < a.size() - 1; ++i)
	{
		for (int j = 0; j < a.size() - i - 1; ++j)
		{
			Object tmp;
			if (a[j] > a[j + 1])
			{
				tmp = a[j];
				a[j] = a[j + 1];
				a[j + 1] = tmp;
			}
		}
	}
}

#endif

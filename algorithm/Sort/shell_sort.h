#ifndef SHELL_SORT_H
#define SHELL_SORT_H

#include <vector>
using std::vector;
/*
 *希尔排序：缩减增量排序
 *增量序列的选择会影响算法的运行时间复杂度，用希尔增量时最坏运行时间为O(n2),用Hibbard时为O(n3/2)
 */
template <typename Object>
void ShellSort(vector<Object> &a)
{
	for (int i = a.size() / 2; i > 0; i /= 2)
	{
		for (int j = i; j < a.size(); ++j)
		{
			Object tmp = a[j];
			int k;
			for (k = j; k >= i && tmp < a[k - i]; k -= i )
				a[k] = a[k - i];
			a[k] = tmp;
		}
	}
}

#endif

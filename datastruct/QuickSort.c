void QuickSort(int a[], int left, int right)
{
	if (left >= right)
			return ;
	int i, j, key;
	i = left;
	j = right;
	key = a[i];

	while (i < j)
	{
		while (i < j && a[j] >= key)
				j--;
		a[i] = a[j];
	//	a[j] = key;

		while (i < j && a[i] <= key)
				i++;
		a[j] = a[i];
	//	a[i] = key;
	}
	a[i] = key;
	QuickSort(a, left, i - 1);
	QuickSort(a, i + 1, right);
}

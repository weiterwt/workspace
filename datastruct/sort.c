void SelectSort(int a[], int n)
{
	int i, j, k;
	int temp;

	for (i = 0; i < n-1; ++i)
	{
		k = i;
		for (j = i+1; j < n; ++j)
		{
			if (a[j] < a[k])
				k = j;
		}

		if (k != i)
		{
			temp = a[i];
			a[i] = a[k];
			a[k] = temp;
		}
	}
}

void InsertSort(int a[], int n)
{
	int i, j;
	
	for (i = 1; i < n; ++i)
	{
		if (a[i] < a[i-1])
		{
			int temp = a[i];
			for (j = i-1; j >= 0 && a[j] > temp; ++j)
					a[j+1] = a[j];
			a[j+1] = temp;
		}
	}
}

void BubbleSort(int a[], int n)
{
	int i, j;
	int temp;
	for (i = 0; i < n-1; ++i)
	{
		for (j = 0; j < n-1-i; ++j)
		{
			if (a[j] > a[j+1])
			{
				temp = a[j];
				a[j] = a[j+1];
				a[j+1] = temp;
			}
		}
	}
}

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
		while (i < j && key <= a[j])
			j--;
		a[i] = a[j];
		while (i < j && key >= a[i])
			i++;
		a[j] = a[i];
	}
	a[i] = key;
	QuickSort(a, left, i-1);
	QuickSort(a, i+1, right);
}

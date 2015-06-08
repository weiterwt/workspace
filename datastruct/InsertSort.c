void InsertSort(int a[], int n)
{
	int i, j;
	int temp;

	for (i = 1; i < n; ++i)
	{
		if (a[i] < a[i-1])
		{
			temp = a[i];
			for (j = i-1; j >= 0; j--)
			{
				if (a[j] > temp)
						a[j+1] = a[j];
			}
			a[j+1] = temp;
		}
	}
}

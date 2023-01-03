#include <stdio.h>

int main()
{
	int arr[5] = { 4,7,2,10,5 };
	int n=5, tmp;

	int low = 0, high = n - 1;

	int i = low - 1, j;
	int pivot = arr[high];

	for (j = low; j < high; j++)
	{
		if (arr[j] < pivot)
		{
			tmp = arr[++i];
			arr[i] = arr[j];
			arr[j] = tmp;
		}
	}

	tmp = arr[++i];
	arr[i] = arr[high];
	arr[high] = tmp;

	for (i = 0; i < n; i++)
	{
		printf("%d ", arr[i]);
	}



}
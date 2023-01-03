#include <iostream>
#define swap(x,y) tmp=x; x=y; y=tmp

using namespace std;

int n;

void quickSort(int arr[], int low, int high) {


	if (low >= high) {
		return;
	}
	else {
		int i = low - 1, j, pivot = arr[high], tmp;
		// divide process

		for (j = low; j < high; j++) {
			if (arr[j] < pivot) {
				i++;
				swap(arr[i], arr[j]);

			}
		}

		i++;
		swap(arr[i], arr[high]);/// pivot 자리찾기​


		for (int k = 0; k < n; k++)
		{
			cout << arr[k] << ' ';
		}
		cout << '\n';

		// conquer process
		quickSort(arr, low, i - 1);
		quickSort(arr, i + 1, high);

	}
}

int main()
{

	//ios::sync_with_stdio(false);
	//cin.tie(NULL);

	scanf("%d", &n);

	int* arr = new int[n];

	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
	}

	quickSort(arr, 0, n - 1);


	delete[] arr;



	return 0;
}

#include <iostream>
#include <cstdlib>

using namespace std;

int binarySearch(int arr[], int low, int high, int target)
{
	int mid;
	while (low <= high) {
		mid = (low + high) / 2;

		if (arr[mid] == target)
			return mid;
		if (arr[mid] > target)
			high = mid - 1;
		else
			low = mid + 1;
	}

	return -1;

}

int main() {

	int i, n, q;

	cin >> n;

	int* arrA = new int[n];

	for (i = 0; i < n; i++)
		cin >> arrA[i];

	cin >> q;

	int* arrB = new int[q];
	for (i = 0; i < q; i++)
		cin >> arrB[i];

	for (i = 0; i < q; i++)
	{
		cout << binarySearch(arrA, 0, n - 1, arrB[i]) << " ";

	}

	delete[] arrA, arrB;


}
#include <iostream>
#include <algorithm>

using namespace std;

void quickSort(int arr[], int low, int high) {

	if (low >= high) {
		return;
	}

	int i = low, j, pivot = arr[high];

	for (j = low; j < high; j++) {
		if (arr[j] < pivot) {
			swap(arr[i++], arr[j]);
		}
	}

	swap(arr[i], arr[high]);

	quickSort(arr, 0, i - 1);
	quickSort(arr, i + 1, high);

}

int lowerBound(int arr[], int nN, int target) {
	int low = 0, high = nN;
	int mid;

	while (low < high) {
		mid = (low + high) / 2;


		if (target <= arr[mid]) {
			high = mid;
		}
		else {
			low = mid + 1;
		}
	}
	return low;
}

int upperBound(int arr[], int nN, int target) {
	int low = 0, high = nN;
	int mid;

	while (low < high) {
		mid = (low + high) / 2;


		if (target < arr[mid]) {
			high = mid;
		}
		else {
			low = mid + 1;
		}
	}
	return low;
}


int main() {

	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	int nN, i;
	cin >> nN;

	int* arr = new int[nN];

	for (i = 0; i < nN; i++) {
		cin >> arr[i];
	}

	sort(arr,arr+nN);

	//quickSort(arr, 0, nN - 1);

	/*for (i = 0; i < nN; i++) {
		cout << arr[i] << ' ';
	}
	cout << '\n';
	*/

	int m, mN, idx;
	cin >> m;

	for (i = 0; i < m; i++) {
		cin >> mN;

		int upper = upperBound(arr, nN, mN);
		int lower = lowerBound(arr, nN, mN);

		//cout << upper << ' ' << lower << '\n';

		if (upper - lower == 0) {
			cout << 0 << ' ';
		}
		else {
			cout << upper - lower << ' ';
		}
	}

}

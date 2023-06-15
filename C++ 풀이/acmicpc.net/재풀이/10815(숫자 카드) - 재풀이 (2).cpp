#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void quickSort(vector<int>& arr, int low, int high) {
	if (low >= high) {
		return;
	}

	int i, j = low;
	int pivot = arr[high];
	for (int i = low; i < high; i++) {
		if (arr[i] < pivot) {
			swap(arr[i], arr[j]);
			j++;
		}
	}

	swap(arr[j], arr[high]);

	quickSort(arr, low, j - 1);
	quickSort(arr, j + 1, high);

}

int searchBinary(vector<int>& arr, int target) {
	int low = 0, high = arr.size();

	for (; low < high;) {
		int mid = (low + high) / 2;

		if (arr[mid] < target) {
			low = mid + 1;
		}
		else {
			high = mid;
		}

	}

	return low;
}

bool lowerBound(vector<int>& arr, int target) {
	int idx = searchBinary(arr, target);
	return (idx < arr.size() && arr[idx] == target) ? 1 : 0;
}

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	int n;
	cin >> n;

	vector<int> nCard(n);
	for (int i = 0; i < n; i++) {
		cin >> nCard[i];
	}

	quickSort(nCard, 0, nCard.size() - 1);

	int m;
	cin >> m;

	int card;
	for (int i = 0; i < m; i++) {
		cin >> card;
		cout << lowerBound(nCard, card) << ' ';
	}

	return 0;
}
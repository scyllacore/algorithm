#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void quickSort(vector<int>& arr, int low, int high) {

	if (low >= high) {
		return;
	}

	int i = low, j, pivot = arr[high];

	for (int j = low; j < high; j++) {
		if (arr[j] < pivot) {
			swap(arr[i++], arr[j]);
		}
	}

	swap(arr[i], arr[high]);

	quickSort(arr, low, i - 1);
	quickSort(arr, i + 1, high);
}

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	int n, m;
	cin >> n >> m;

	vector<int > arr(n + m);

	for (int i = 0; i < n + m; i++) {
		cin >> arr[i];
	}

	quickSort(arr, 0, n + m - 1);

	for (int i = 0; i < n + m; i++) {
		cout << arr[i] << ' ';
	}
}


//https://reakwon.tistory.com/38
//병합정렬을 이용해야하지만 편의상 퀵정렬로 처리했다. 
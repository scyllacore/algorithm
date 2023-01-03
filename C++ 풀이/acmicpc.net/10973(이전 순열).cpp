#include <iostream>
#include <algorithm>

using namespace std;

int arr[10000]{ 0 };

bool prevPermutation(int len) {
	int i, j;
	i = j = len - 1;

	//arr[i-1] > arr[i]
	while (i >= 1 && arr[i - 1] <= arr[i]) {
		i--;
	}

	if (i <= 0) { return false; }

	//arr[i-1] > arr[j]
	while (j >= 1 && arr[i - 1] <= arr[j]) {
		j--;
	}

	swap(arr[i - 1], arr[j]);
	//오름차순 정렬 되어있는 상태

	j = len - 1;

	while (i < j) {
		swap(arr[i], arr[j]); // 내림차순 정렬
		i++, j--;
	}

	return true;

}

int main() {

	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	int n;
	cin >> n;

	int i;
	for (i = 0; i < n; i++) {
		cin >> arr[i];
	}

	if (prevPermutation(n)) {
		for (i = 0; i < n; i++) {
			cout << arr[i] << ' ';
		}
	}
	else {
		cout << -1;
	}

	return 0;

}

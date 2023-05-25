#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int getLowerBound(vector<int>& arr, int& target) {
	int low = 0, high = arr.size();
	int mid;

	for (; low < high;) {
		mid = (low + high) / 2;

		if (arr[mid] < target) {
			low = mid + 1;
		}
		else {
			high = mid;
		}
	}

	return low;
}

int getUpperBound(vector<int>& arr, int& target) {
	int low = 0, high = arr.size();
	int mid;

	for (; low < high;) {
		mid = (low + high) / 2;

		if (arr[mid] <= target) {
			low = mid + 1;
		}
		else {
			high = mid;
		}
	}

	return low;
}

int binarySearch(vector<int>& arr, int& target) {
	int idx = getLowerBound(arr, target);
	return idx < arr.size() && arr[idx] == target ? idx : -1;
}

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	int n, m;
	cin >> n;

	vector<int> sangCard(n);
	for (int i = 0; i < n; i++) {
		cin >> sangCard[i];
	}

	sort(sangCard.begin(), sangCard.end());

	cin >> m;
	int otherCard;
	for (int i = 0; i < m; i++) {
		cin >> otherCard;

		int lowIdx = binarySearch(sangCard, otherCard);

		if (lowIdx >= 0) {
			int highIdx = getUpperBound(sangCard, otherCard);

			cout << highIdx - lowIdx;
		}
		else {
			cout << 0;
		}
		cout << ' ';
	}

	return 0;
}
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int binarySearch(vector<int>& arr, int target) {
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

int lowerBound(vector<int>& arr, int target) {
	int idx = binarySearch(arr, target);
	return idx;

	/*if (idx < arr.size() && arr[idx] == target) {
		return idx;
	}

	return -1;*/
}

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	int n;
	cin >> n;

	vector<int> childNum(n);

	for (int i = 0; i < n; i++) {
		cin >> childNum[i];
	}

	vector<int> dp;

	for (int i = 0; i < n; i++) {
		int idx = lowerBound(dp, childNum[i]);


		if (idx >= dp.size()) {
			dp.push_back(childNum[i]);
		}
		else {
			dp[idx] = childNum[i];
		}
	}

	cout << n - dp.size();

	return 0;
}
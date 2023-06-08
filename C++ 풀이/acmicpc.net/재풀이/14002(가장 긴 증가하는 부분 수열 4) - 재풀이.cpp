#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int binarySearch(vector<int>& dp, int& target) {
	int low = 0, high = dp.size();
	int mid;

	for (; low < high;) {
		mid = (low + high) / 2;

		if (dp[mid] < target) {
			low = mid + 1;
		}
		else {
			high = mid;
		}

	}

	return low;
}

int lowerBound(vector<int>& dp, int& target) {
	int idx = binarySearch(dp, target);
	return idx;
}

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	int n;
	cin >> n;

	vector<int> arr(n);

	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	vector<int> dp;

	vector<int> sequenceSize(n);

	int maxSize = 0;
	int maxIdx = 0;

	for (int i = 0; i < n; i++) {
		int idx = lowerBound(dp, arr[i]);

		if (idx >= dp.size()) {
			dp.push_back(arr[i]);
		}
		else {
			dp[idx] = arr[i];
		}

		sequenceSize[i] = idx + 1;

		if (sequenceSize[i] > maxSize) {
			maxSize = sequenceSize[i];
			maxIdx = i;
		}

	}

	vector<int> ans;

	for (int i = maxIdx; i >= 0; i--) {
		if (sequenceSize[i] == maxSize) {
			ans.push_back(arr[i]);
			maxSize--;
		}
	}

	cout << ans.size() << '\n';

	for (int i = ans.size() - 1; i >= 0; i--) {
		cout << ans[i] << ' ';
	}

	return 0;
}
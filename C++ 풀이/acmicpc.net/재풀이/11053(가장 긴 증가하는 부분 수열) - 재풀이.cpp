#include <iostream>
#include <vector>

using namespace std;

int binarySearch(vector<int>& arr, int& target) {
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

int getLower(vector<int>& arr, int& target) {
	int idx = binarySearch(arr, target);
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

	vector<int> lis;
	vector<int> dp;

	int maxIdx = 0;
	int maxSize = 0;

	for (int i = 0; i < n; i++) {
		int idx = getLower(lis, arr[i]);

		if (idx >= lis.size()) {
			lis.push_back(arr[i]);
		}
		else {
			lis[idx] = arr[i];
		}

		dp.push_back(idx + 1);

		if (idx + 1 > maxSize) {
			maxSize = idx + 1;
			maxIdx = i;
		}
	}

	vector<int> ans;

	for (int i = maxIdx; i >= 0; i--) {
		if (dp[i] == maxSize) {
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

/*#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

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

	vector<int> dp(n, 1);

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < i; j++) {
			if (arr[i] > arr[j]) {
				dp[i] = max(dp[j] + 1, dp[i]);
			}
		}
	}

	cout << *max_element(dp.begin(), dp.end());
	return 0;

}*/

/*
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

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

	vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));

	fill(dp[1].begin(), dp[1].end(), 1);

	for (int i = 1; i <= n; i++) {
		dp[i][0] = dp[i-1][n];
		for (int j = 1; j <= n; j++) {
			if (arr[i - 1] > arr[j - 1]) {
				dp[i][j] = dp[i - 1][j - 1] + 1;
			}
			else {
				dp[i][j] = dp[i][j - 1];
			}
		}
	}

	for (int i = 0; i <= n; i++) {
		for (int j = 0; j <= n; j++) {
			cout << dp[i][j] << ' ';
		}
		cout << '\n';
	}

	cout << dp[n][n];
	return 0;

}
*/
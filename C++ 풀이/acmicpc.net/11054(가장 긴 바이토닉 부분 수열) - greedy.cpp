#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {

	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	int n, i, idx, ans = 0;
	cin >> n;

	int* arr = new int[n + 1];
	for (i = 1; i <= n; i++) {
		cin >> arr[i];
	}

	int** dpLen = new int* [2];
	for (i = 0; i < 2; i++) {
		dpLen[i] = new int[n + 1];
	}
	vector<int> dp;


	for (i = 1; i <= n; i++) {
		idx = lower_bound(dp.begin(), dp.end(), arr[i]) - dp.begin();

		if (idx + 1 > dp.size()) {
			dp.push_back(arr[i]);
		}
		else {
			dp[idx] = arr[i];
		}

		dpLen[0][i] = idx + 1; // dp.size()가 아님. 값이 들어가는 위치를 따져 길이를 알아내야함. 
	}

	dp.clear();

	for (i = n; i >= 1; i--) {
		idx = lower_bound(dp.begin(), dp.end(), arr[i]) - dp.begin();

		if (idx + 1 > dp.size()) {
			dp.push_back(arr[i]);
		}
		else {
			dp[idx] = arr[i];
		}

		dpLen[1][i] = idx + 1;
	}


	for (i = 1; i <= n; i++) {
		ans = max(dpLen[0][i] + dpLen[1][i], ans);
	}

	cout << ans - 1;

	delete[] dpLen[0];
	delete[] dpLen[1];
	delete[] dpLen;
	delete[] arr;
	return 0;

}
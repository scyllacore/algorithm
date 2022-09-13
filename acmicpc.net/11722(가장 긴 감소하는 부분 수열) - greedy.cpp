#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {

	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	int n, i, j, idx;
	cin >> n;

	int* arr = new int[n + 1];
	vector<int> dp;

	for (i = 1; i <= n; i++) {
		cin >> arr[i];
	}

	dp.push_back(arr[n]);


	for (i = n - 1; i >= 1; i--) { // 거꾸로 탐색해서 감소효과를 줌
		idx = lower_bound(dp.begin(), dp.end(), arr[i]) - dp.begin();

		if (idx >= dp.size()) {
			dp.push_back(arr[i]);
		}
		else {
			dp[idx] = arr[i];
		}

	}

	/*for (auto i : dp) {
		cout << i << ' ';
	}
	cout << '\n';*/



	cout << dp.size();

	delete[] arr;
	return 0;


}
#include <iostream>
#include <algorithm>

using namespace std;

int main() {

	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	int n, i, j, ans = 0;
	cin >> n;

	int* arr = new int[n + 1];
	int** dp = new int*[2];
	for (i = 0; i < 2; i++) {
		dp[i] = new int[n + 1];
	}

	for (i = 1; i <= n; i++) {
		cin >> arr[i];
	}


	dp[0][1] = 1;
	dp[1][n] = 1;

	for (i = 2; i <= n; i++) {
		dp[0][i] = 1;

		for (j = i - 1; j >= 1; j--) {
			if (arr[i] > arr[j])
			{
				dp[0][i] = max(dp[0][j] + 1, dp[0][i]);
			}
		}


	}


	for (i = n - 1; i >= 1; i--) {
		dp[1][i] = 1;
		for (j = i + 1; j <= n; j++) {
			if (arr[i] > arr[j])
			{
				dp[1][i] = max(dp[1][j] + 1, dp[1][i]);
			}
		}

	}

	for (i = 1; i <= n; i++) {

		ans = max(dp[0][i] + dp[1][i], ans);
	}

	/*
		for (i = 1; i <= n; i++) {
		cout << dp[0][i] << ' ';
	}
	cout << '\n';
	for (i = 1; i <= n; i++) {
		cout << dp[1][i] << ' ';
	}

	cout << '\n';

	 */

	cout << ans - 1;

	delete[] dp[0];
	delete[] dp[1];
	delete[] dp;
	delete[] arr;
	return 0;

}
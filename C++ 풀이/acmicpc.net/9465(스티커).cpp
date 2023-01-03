#include <iostream>
#include <algorithm>

using namespace std;

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	int tc, n, i, j;
	cin >> tc;

	for (i = 0; i < tc; i++) {
		cin >> n;

		int** dp = new int*[3];
		int** arr = new int*[3];


		for (j = 0; j < 3; j++) {
			dp[j] = new int[n + 1];
			arr[j] = new int[n + 1];
		}

		for (j = 1; j <= n; j++) {
			cin >> arr[0][j];
		}
		for (j = 1; j <= n; j++) {
			cin >> arr[1][j];
		}


		dp[0][0] = dp[1][0] = dp[2][0] = 0;

		for (j = 1; j <= n; j++) {
			dp[0][j] = max(dp[1][j - 1], dp[2][j - 1]);
			dp[1][j] = max(dp[0][j - 1], dp[2][j - 1]) + arr[0][j];
			dp[2][j] = max(dp[0][j - 1], dp[1][j - 1]) + arr[1][j];

		}

		/*for (int k = 0; k < 3; k++) {
			for (j = 1; j <= n; j++) {
				cout << dp[k][j] << ' ';
			}
			cout << '\n';
		}*/

		cout << max(dp[0][n], max(dp[1][n], dp[2][n])) << '\n';
		delete[] dp;
		delete[] arr;

	}

	return 0;

}
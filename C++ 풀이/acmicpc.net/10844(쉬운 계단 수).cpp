#include <iostream>

using namespace std;

#define MOD (int)1e9

int main() {

	cin.tie(0);
	ios::sync_with_stdio(false);

	int dp[101][10] = { {0},{0,1,1,1,1,1,1,1,1,1} };
	int n;

	cin >> n;

	int i, j;

	for (i = 2; i <= n; i++) {
		dp[i][0] = dp[i - 1][1] % MOD;

		for (j = 1; j <= 8; j++) {
			dp[i][j] = (dp[i - 1][j - 1] + dp[i - 1][j + 1]) % MOD;
		}
		dp[i][9] = dp[i - 1][8] % MOD;

	}

	unsigned long long result = 0;

	for (i = 0; i <= 9; i++) {
		result += dp[n][i];
	}

	cout << result % MOD;
	return 0;

}
#include <iostream>
#include <numeric>
#define MOD 10007

using namespace std;

int dp[1001][10] = { {0},{1,1,1,1,1,1,1,1,1,1} };

int main() {

	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	int n, i, j;

	cin >> n;

	for (i = 2; i <= n; i++) {
		dp[i][0] = 1;
		for (j = 1; j < 10; j++) {
			dp[i][j] = (dp[i - 1][j] + dp[i][j - 1]) % MOD;
		}
	}

	cout << accumulate(&dp[n][0], &dp[n][10], 0) % MOD;

	return 0;
}
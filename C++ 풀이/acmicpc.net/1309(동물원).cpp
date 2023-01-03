#include <iostream>
#define MOD 9901

using namespace std;

int main() {

	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	int n,i;
	cin >> n;

	int** dp = new int* [n + 1];
	for (i = 1; i <= n; i++) { dp[i] = new int[3]; }

	dp[1][0] = dp[1][1] = dp[1][2] = 1;

	for (i = 2; i <= n; i++) {

		dp[i][0] = (dp[i - 1][0] + dp[i - 1][1] + dp[i - 1][2]) % MOD;
		dp[i][1] = (dp[i - 1][0] + dp[i - 1][2]) % MOD;
		dp[i][2] = (dp[i - 1][0] + dp[i - 1][1]) % MOD;
	}

	cout << (dp[n][0] + dp[n][1] + dp[n][2]) % MOD;

	for (i = 1; i <= n; i++) { delete[] dp[i]; }
	delete[] dp;


}
#include <iostream>
#include <stdio.h>

using namespace std;

const int mod = 1e9 + 9;
const int MAXN = 100000;
unsigned long long dp[MAXN + 1][4];

void solve(void) {

	dp[1][1] = dp[2][2] = dp[3][1] = dp[3][2] = dp[3][3] = 1;

	for (int n = 4; n <= MAXN; n++) {
		dp[n][1] = (dp[n - 1][2] + dp[n - 1][3]) % mod;
		dp[n][2] = (dp[n - 2][1] + dp[n - 2][3]) % mod;
		dp[n][3] = (dp[n - 3][1] + dp[n - 3][2]) % mod;
	}
}

int main() {
	int t;
	scanf("%d", &t);

	solve();
	while (t--) {
		int n;
		scanf("%d", &n);
		printf("%d\n", (dp[n][1] + dp[n][2] + dp[n][3]) % mod);
	}
	return 0;
}

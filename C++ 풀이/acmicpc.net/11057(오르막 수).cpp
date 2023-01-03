#include <iostream>
#define MOD 10007

using namespace std;

int main() {

	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	int dp[1001][10] = { {0},{1,1,1,1,1,1,1,1,1,1} };
	int n, i,j,k,ans=0;

	cin >> n;

	for (i = 2; i <= n; i++) {
		for (j = 0; j < 10; j++) {
			for (k = j; k >= 0; k--) {
				dp[i][j] += dp[i-1][k];
			}
			dp[i][j] %= MOD;

		}
	}

	for (i = 0; i < 10; i++)
	{
		ans += dp[n][i];
	}

	cout << ans%MOD;



}
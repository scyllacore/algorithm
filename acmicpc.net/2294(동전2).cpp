#include <iostream>
#include <algorithm>

using namespace std;

#define MAX 100001

int coin[101];
int dp[101][MAX] = { {0} };

int main() {

	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	int n, k;

	cin >> n >> k;

	int i, j;

	for (i = 0; i <= 100; i++) {
		fill(&dp[i][1], &dp[i][MAX], MAX);
	}


	for (i = 1; i <= n; i++) {
		cin >> coin[i];
	}

	for (i = 1; i <= n; i++) {
		for (j = 1; j <= k; j++) {
			dp[i][j] = dp[i - 1][j];
			if (j >= coin[i]) {
				dp[i][j] = min(dp[i][j - coin[i]] + 1, dp[i][j]);
			}
		}

	}

	/*for (i = 1; i <= n; i++) {
		for (j = 1; j <= k; j++) {
			cout << dp[i][j] << ' ';
		}
		cout << '\n';
	}*/




	if (dp[n][k] == MAX) {
		cout << -1;
	}
	else {
		cout << dp[n][k];
	}


}


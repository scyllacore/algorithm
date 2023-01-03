#include <iostream>
#include <algorithm>

using namespace std;

#define MAX 99999

int coin[101];
int dp[100001];

int main() {

	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	int n, k;

	cin >> n >> k;

	int i, j;

	fill_n(dp, 10001, MAX);

	for (i = 1; i <= n; i++) {
		cin >> coin[i];
		dp[coin[i]] = 1;
	}

	for (i = 1; i <= n; i++) {
		for (j = coin[i] + 1; j <= k; j++) {
			dp[j] = min(dp[j - coin[i]] + 1, dp[j]);
		}

		/*for (j = 1; j <= k; j++) {
			cout << dp[j] << ' ';
		}
		cout << '\n';*/
	}


	if (dp[k] == MAX) {
		cout << -1;
	}
	else {
		cout << dp[k];
	}


}


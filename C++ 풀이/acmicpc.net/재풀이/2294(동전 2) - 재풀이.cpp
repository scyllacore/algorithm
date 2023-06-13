#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#define MAXF (int)1e4+1

int dp[MAXF];

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	int n, k;
	cin >> n >> k;

	vector<int> coin(n + 1);
	fill(&dp[0], &dp[MAXF], MAXF);

	for (int i = 1; i <= n; i++) {
		cin >> coin[i];
	}

	dp[0] = 0;

	for (int i = 1; i <= n; i++) {
		for (int j = coin[i]; j <= k; j++) {
			dp[j] = min(dp[j - coin[i]] + 1, dp[j]);
		}
	}

	cout << (dp[k] == MAXF ? -1 : dp[k]);
	return 0;
}


/*
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#define SIZE 100
#define MAXF (int)1e4+1

int dp[SIZE + 1][SIZE * SIZE + 1];

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	int n, k;
	cin >> n >> k;

	vector<int> coin(n + 1);
	fill(&dp[0][0], &dp[SIZE - 1][SIZE * SIZE + 1], MAXF);

	for (int i = 1; i <= n; i++) {
		cin >> coin[i];
		dp[i][0] = 0;
	}


	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= k; j++) {
			dp[i][j] = dp[i - 1][j];
			if (j - coin[i] >= 0) {
				dp[i][j] = min(dp[i][j - coin[i]] + 1, dp[i][j]);
			}
		}
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= k; j++) {
			cout << dp[i][j] << ' ';
		}
		cout << '\n';
	}

cout << (dp[n][k] == MAXF ? -1 : dp[n][k]);
return 0;
}
*/
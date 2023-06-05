#include <iostream>
#include <vector>

using namespace std;

#define SIZE 100

int dp[SIZE * SIZE + 1] = { {0} };

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	int n, k;
	cin >> n >> k;

	vector<int> coin(n + 1);
	for (int i = 1; i <= n; i++) {
		cin >> coin[i];
	}

	dp[0] = 1;

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= k; j++) {
			if (j - coin[i] >= 0) {
				dp[j] += dp[j - coin[i]];
			}
		}
	}

	cout << dp[k];

}

/*
#include <iostream>
#include <vector>

using namespace std;

#define SIZE 100

int dp[SIZE + 1][SIZE * SIZE + 1] = { {0} };

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	int n, k;
	cin >> n >> k;

	vector<int> coin(n+1);
	for (int i = 1; i <= n; i++) {
		cin >> coin[i];
		dp[i][0] = 1;
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= k; j++) {
			if (j - coin[i] >= 0) {
				dp[i][j] = dp[i - 1][j] + dp[i][j - coin[i]];
			}
			else {
				dp[i][j] = dp[i - 1][j];
			}
		}
	}

	cout << dp[n][k];

}
*/
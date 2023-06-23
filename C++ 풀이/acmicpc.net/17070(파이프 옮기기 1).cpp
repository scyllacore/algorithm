#include <iostream>
#include <numeric>

using namespace std;

#define SIZE 16 + 1

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	bool mapNN[SIZE][SIZE] = { {0} };
	int dp[SIZE][SIZE][3] = { {{0}} };


	int n;
	cin >> n;

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> mapNN[i][j];
		}
	}

	dp[1][2][0] = 1;

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (mapNN[i][j]) {
				continue;
			}

			if (!mapNN[i][j - 1]) {
				dp[i][j][0] += dp[i][j - 1][0] + dp[i][j - 1][2];
			}

			if (!mapNN[i - 1][j]) {
				dp[i][j][1] += dp[i - 1][j][1] + dp[i - 1][j][2];
			}

			if (!mapNN[i][j - 1] && !mapNN[i - 1][j] && !mapNN[i - 1][j - 1]) {
				dp[i][j][2] += dp[i - 1][j - 1][0] + dp[i - 1][j - 1][1] + dp[i - 1][j - 1][2];
			}
		}
	}

	cout << accumulate(&dp[n][n][0], &dp[n][n][3], 0);
	return 0;
}
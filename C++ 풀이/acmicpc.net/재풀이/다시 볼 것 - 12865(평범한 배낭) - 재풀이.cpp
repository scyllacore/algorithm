#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#define SIZE 100
#define MAX_WEIGHT (int)1e5

int dp[SIZE + 1][MAX_WEIGHT + 1] = { {0} };

struct bag {
	int w, v;
};

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	int n, k;
	cin >> n >> k;

	vector<bag> bags(n + 1);

	for (int i = 1; i <= n; i++) {
		cin >> bags[i].w >> bags[i].v;
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= k; j++) {
			dp[i][j] = dp[i - 1][j];
			if (j - bags[i].w >= 0) {
				dp[i][j] = max(dp[i - 1][j - bags[i].w] + bags[i].v, dp[i][j]);
			}
		}
	}

	/*for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= k; j++) {
			cout << dp[i][j] << ' ';
		}
		cout << '\n';
	}*/


	cout << dp[n][k];
	return 0;

}
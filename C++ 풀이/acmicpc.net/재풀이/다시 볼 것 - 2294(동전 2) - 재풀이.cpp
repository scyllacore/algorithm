#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#define SIZE (int)1e4

int dp[SIZE + 1];

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	fill(&dp[1], &dp[SIZE + 1], SIZE + 1);
	dp[0] = 0;

	int n, k;
	cin >> n >> k;

	vector<int> coin(n + 1);

	for (int i = 1; i <= n; i++) {
		cin >> coin[i];
	}


	for (int i = 1; i <= n; i++) {
		for (int j = coin[i]; j <= k; j++) {
			dp[j] = min(dp[j], dp[j - coin[i]] + 1);
		}
	}

	if (dp[k] > SIZE) {
		cout << -1;
	}
	else {
		cout << dp[k];
	}

	return 0;

}
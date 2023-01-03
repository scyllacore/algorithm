#include <iostream>
#include <algorithm>

using namespace std;

#define MAX (int)(1e5+1)

struct bag {
	int w, v;
}bagInfo[101];

int dp[101][MAX] = { 0 };

int main() {

	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	int n, k;
	cin >> n >> k;

	int i, j;

	for (i = 1; i <= n; i++) {
		cin >> bagInfo[i].w >> bagInfo[i].v;
	}

	for (i = 1; i <= n; i++) {
		for (j = 1; j <= k; j++) {
			dp[i][j] = dp[i - 1][j];
			if (j - bagInfo[i].w >= 0) {
				dp[i][j] = max(dp[i - 1][j - bagInfo[i].w] + bagInfo[i].v , dp[i][j]);
			}
		}
	}

	cout << dp[n][k];

	return 0;
}

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


struct people {
	int l, j;
};

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	int n;
	cin >> n;

	vector<people> p(n + 1);

	for (int i = 1; i <= n; i++)
	{
		cin >> p[i].l;
	}

	for (int i = 1; i <= n; i++)
	{
		cin >> p[i].j;
	}

	int dp[21][101] = { {0} };

	int ans = 0;

	for (int i = 1; i <= n; i++) {
		for (int j = 0; j <= 100; j++) {
			if (p[i].l + j < 100) {
				dp[i][j] = max(dp[i - 1][p[i].l + j] + p[i].j, dp[i - 1][j]);
			}
			else {
				dp[i][j] = dp[i - 1][j];
			}
			ans = max(dp[i][j], ans);
		}

	}

	cout << ans;
	return 0;
}
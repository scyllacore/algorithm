#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	int n, m;
	cin >> n >> m;

	vector<vector<int>> mirror(n + 1, vector<int>(m + 1));

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			cin >> mirror[i][j];
		}
	}

	vector<vector<int>> dp(n + 1, vector<int>(m + 1));
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			dp[i][j] = mirror[i][j] + max(dp[i - 1][j - 1], max(dp[i][j - 1], dp[i - 1][j]));
		}
	}

	cout << dp[n][m];
	return 0;

}

/*
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	int n, m;
	cin >> n >> m;

	vector<vector<int>> mirror(n + 1, vector<int>(m + 1, 0));
	vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			cin >> mirror[i][j];
		}
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			dp[i][j] = dp[i - 1][j] + mirror[i][j];
			dp[i][j] = max(dp[i][j - 1] + mirror[i][j], dp[i][j]);
			dp[i][j] = max(dp[i - 1][j - 1] + mirror[i][j], dp[i][j]);
		}
	}

	cout << dp[n][m];
	return 0;
}
*/
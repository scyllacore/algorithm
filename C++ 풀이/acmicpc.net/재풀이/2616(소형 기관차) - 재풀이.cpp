#include <iostream>
#include <algorithm>

using namespace std;

#define SIZE (int)5e4

int rail[SIZE + 1] = { 0 };
int dp[4][SIZE + 1] = { {0} };

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	int n;
	cin >> n;

	for (int i = 1; i <= n; i++) {
		cin >> rail[i];
		rail[i] += rail[i - 1];
	}

	int group;
	cin >> group;

	for (int i = 1; i <= 3; i++) {
		for (int j = i * group; j <= n; j++) {
			dp[i][j] = max(dp[i][j - 1], dp[i - 1][j - group] + rail[j] - rail[j - group]);
		}
	}

	/*for (int i = 1; i <= 3; i++) {
		for (int j = 1; j <= n; j++) {
			cout << dp[i][j] << ' ';
		}
		cout << '\n';
	}*/

	cout << dp[3][n];
	return 0;
}
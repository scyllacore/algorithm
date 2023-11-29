#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


struct people {
	int sad, happy;
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
		cin >> p[i].sad;
	}

	for (int i = 1; i <= n; i++)
	{
		cin >> p[i].happy;
	}

	int dp[21][101] = { {0} };

	int ans = 0;

	for (int i = 1; i <= n; i++) {
		for (int j = 0; j <= 100; j++) {
			if (p[i].sad + j < 100) {
				dp[i][j] = max(dp[i - 1][p[i].sad + j] + p[i].happy, dp[i - 1][j]);
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

/*
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


struct people {
	int sad, happy;
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
		cin >> p[i].sad;
	}

	for (int i = 1; i <= n; i++)
	{
		cin >> p[i].happy;
	}

	int dp[21][101] = { {0} };

	int ans = 0;

	for (int i = 1; i <= n; i++) {
		for (int j = 5; j >= 0; j--) {
			if (j - p[i].sad > 0) {
				dp[i][j] = max(dp[i - 1][j - p[i].sad] + p[i].happy, dp[i - 1][j]);
			}
			else {
				dp[i][j] = dp[i - 1][j];
			}
			ans = max(dp[i][j], ans);
		}

	}


	for (int i = 0; i <= n; i++) {
		for (int j = 0; j <= 5; j++) {
			cout << dp[i][j] << ' ';
		}
		cout << '\n';
	}



	cout << ans;
	return 0;
}

input : 

3
1 2 2
2 3 5
*/
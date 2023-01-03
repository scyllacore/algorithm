#include <iostream>

using namespace std;

int main() {

	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	int n, i, j;
	cin >> n;

	int dp[101][10] = { {0},{0,1,1,1,1,1,1,1,1,1} };
	unsigned long long result = 0;

	for (i = 2; i <= n; i++)
	{
		dp[i][0] = dp[i - 1][1] % 1000000000;

		for (j = 1; j < 9; j++)
		{
			dp[i][j] = (dp[i - 1][j - 1] + dp[i - 1][j + 1]) % 1000000000;
		}
		dp[i][9] = dp[i - 1][8] % 1000000000;
	}

	for (i = 0; i < 10; i++)
	{
		result += dp[n][i];
	}

	cout << result % 1000000000;

}
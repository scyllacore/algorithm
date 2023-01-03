#include <iostream>

using namespace std;

int main()
{
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	int n,i;
	cin >> n;

	if (n == 1 || n == 2) {
		cout << 1;
		return 0;
	}

	long long** dp = new long long* [n+1];

	for (i = 1; i <= n; i++)
	{
		dp[i] = new long long[2];
	}

	dp[1][0] = dp[2][1] = 0;
	dp[1][1] = dp[2][0] = 1;


	for (i = 3; i <= n; i++)
	{
		dp[i][0] = dp[i - 2][0] + dp[i - 1][0];
		dp[i][1] = dp[i - 2][1] + dp[i - 1][1];
	}

	cout << dp[n][0] + dp[n][1];

	delete[] dp;
	return 0;

}
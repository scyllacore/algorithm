#include <iostream>

using namespace std;

int main()
{
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	int n, i;
	cin >> n;

	long long dp[91] = { 0,1,1 };


	for (i = 3; i <= n; i++)
	{
		dp[i] = dp[i - 1] + dp[i - 2];
	}

	cout << dp[n];
	
	return 0;

}
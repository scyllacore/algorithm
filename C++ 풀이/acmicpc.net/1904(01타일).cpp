#include <iostream>

using namespace std;

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int n,i;
	int dp[1000001] = { 0,1,2 };

	cin >> n;

	for (i = 3; i <= n; i++)
	{
		dp[i] = (dp[i - 1] + dp[i - 2])%15746;
	}


	cout << dp[n];


}
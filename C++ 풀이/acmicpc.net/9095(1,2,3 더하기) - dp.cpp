#include <iostream>

using namespace std;

int main()
{
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);


	int n, num, i;

	cin >> n;

	int dp[11] = { 0,1,2,4 };


	for (i = 4; i < 11; i++)
	{
		dp[i] = dp[i - 1] + dp[i - 2] + dp[i - 3];
	}

	for (i = 0; i < n; i++) {
		cin >> num;
		cout << dp[num] << '\n';
	}

	return 0;
}

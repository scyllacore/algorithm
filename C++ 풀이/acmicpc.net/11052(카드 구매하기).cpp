#include <iostream>
#include <algorithm>

using namespace std;

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	int n, i, j;
	cin >> n;

	int* arr = new int[n + 1];
	int* dp = new int[n + 1];


	for (i = 1; i <= n; i++)
	{
		cin >> arr[i];
	}

	for (i = 1; i <= n; i++)
	{
		dp[i] = arr[i];
		for (j = 1; j <= (i / 2); j++)
		{
			dp[i] = max(dp[i - j] + dp[j], dp[i]);
		}
	}

	cout << dp[n];

	delete[] arr;
	delete[] dp;

	return 0;
}
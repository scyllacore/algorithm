#include <iostream>
#include <algorithm>

using namespace std;

int main() {

	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	int n, i;
	cin >> n;

	int* arr = new int[n + 1];
	int* dp = new int[n + 1];

	for (i = 1; i <= n; i++)
	{
		cin >> arr[i];
	}

	dp[0] = 0;
	dp[1] = arr[1];
	dp[2] = arr[1] + arr[2];


	for (i = 3; i <= n; i++) {
		dp[i] = dp[i - 1];
		dp[i] = max(arr[i] + dp[i - 2], dp[i]);
		dp[i] = max(arr[i] + arr[i - 1] + dp[i - 3], dp[i]);
	}


	cout << dp[n];

	delete[] dp;
	delete[] arr;

	return 0;

}
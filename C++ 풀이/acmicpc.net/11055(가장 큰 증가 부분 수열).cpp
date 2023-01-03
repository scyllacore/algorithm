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

	dp[1] = arr[1];

	for (i = 2; i <= n; i++) {
		dp[i] = arr[i];
		for (j = i - 1; j >= 1; j--) {
			if (arr[i] > arr[j]) {
				dp[i] = max(dp[j] + arr[i], dp[i]);
			}
		}
	}

	cout << *max_element(&dp[1], &dp[n + 1]);

	delete[] arr;
	delete[] dp;
	return 0;


}
#include <iostream>
#include <algorithm>

using namespace std;

int main() {

	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	int n, i;
	cin >> n;

	int** arr = new int* [n + 1];
	int** dp = new int* [n + 1];

	for (i = 0; i <= n; i++) {
		arr[i] = new int[3];
		dp[i] = new int[3];
	}

	for (i = 1; i <= n; i++) {
		cin >> arr[i][0] >> arr[i][1] >> arr[i][2];
	}



	dp[0][0] = dp[0][1] = dp[0][2] = 0;

	for (i = 1; i <= n; i++) {
		dp[i][0] = min(dp[i - 1][1], dp[i - 1][2]) + arr[i][0];
		dp[i][1] = min(dp[i - 1][0], dp[i - 1][2]) + arr[i][1];
		dp[i][2] = min(dp[i - 1][0], dp[i - 1][1]) + arr[i][2];
	}


	cout << *min_element(&dp[n][0], &dp[n][3]);

	for (i = 0; i <= n; i++) {
		delete[] arr[i];
		delete[] dp[i];
	}
	delete[] arr;
	delete[] dp;

}

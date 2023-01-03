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

	for (i = 1; i <= n; i++) {
		cin >> arr[i];
	}

	/*
	reverse(arr + 1, arr + n + 1);

	dp[1] = 1;

	for (i = 2; i <= n; i++) {
		dp[i] = 1;
		for (j = i - 1; j >= 1; j--) {
			if (arr[i] > arr[j]) {
				dp[i] = max(dp[i], dp[j] + 1);
			}
		}
	}
	*/

	dp[n] = 1;
	for (i = n-1; i >= 1; i--) {
		dp[i] = 1;
		for (j = i + 1; j <= n; j++) {
			if (arr[i] > arr[j]) {
				dp[i] = max(dp[i], dp[j] + 1);
			}
		}
	}



	cout << *max_element(&dp[1], &dp[n + 1]);

	delete[] arr;
	delete[] dp;
	return 0;

}
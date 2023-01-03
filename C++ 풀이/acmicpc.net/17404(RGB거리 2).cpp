#include <iostream>
#define MAX 1000*1000+1

using namespace std;

int main() {

	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	int n, i, k, ans = MAX;
	int arr[1001][3], dp[1001][3];

	cin >> n;

	for (i = 1; i <= n; i++) {
		cin >> arr[i][0] >> arr[i][1] >> arr[i][2];
	}

	for (k = 0; k < 3; k++) {

		dp[1][0] = dp[1][1] = dp[1][2] = MAX;
		dp[1][k] = arr[1][k];

		for (i = 2; i <= n; i++) {
			dp[i][0] = min(dp[i - 1][1], dp[i - 1][2]) + arr[i][0];
			dp[i][1] = min(dp[i - 1][0], dp[i - 1][2]) + arr[i][1];
			dp[i][2] = min(dp[i - 1][0], dp[i - 1][1]) + arr[i][2];
		}

		for (i = 0; i < 3; i++) {
			if (i == k) continue;
			ans = min(dp[n][i], ans);
		}
	}


	cout << ans;
	return 0;



}
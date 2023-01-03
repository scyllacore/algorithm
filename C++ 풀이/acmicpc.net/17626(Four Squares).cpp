#include <iostream>
#include <algorithm>

using namespace std;

int dp[50001] = { 0,1,2,3 };

int main() {

	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	int n;

	cin >> n;

	int i, j;

	for (i = 4; i <= n; i++) {
		dp[i] = i;
		for (j = 1; j*j<= i; j++) {
			dp[i] = min(dp[i - j * j] + 1, dp[i]);
		}
	}

	cout << dp[n];
	return 0;

}


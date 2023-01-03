#include <iostream>

using namespace std;

int main() {

	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	int n,i,j;
	int dp[31] = { 1,0,3,0 };

	cin >> n;

	for (i = 4; i <= n; i++) {
		dp[i] = 3 * dp[i-2];

		for (j = 4; j <= i; j += 2) {
			dp[i] += 2 * dp[i - j];
		}
	}

	cout << dp[n];

	return 0;

}
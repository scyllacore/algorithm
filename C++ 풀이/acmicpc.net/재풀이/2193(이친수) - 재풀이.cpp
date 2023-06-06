#include <iostream>

using namespace std;

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	long long dp[90 + 1] = { 0,1,1 };

	int n;
	cin >> n;

	for (int i = 3; i <= n; i++) {
		dp[i] = dp[i - 1] + dp[i - 2];
	}

	cout << dp[n];
	return 0;
}
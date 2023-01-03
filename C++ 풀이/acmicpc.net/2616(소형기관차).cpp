#include <iostream>
#include <algorithm>

using namespace std;

int guest[50001] = { 0 };
int dp[4][50001] = { {0} };


int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	int n, maxGuest;

	cin >> n;

	int i,j;

	for (i = 1; i <= n; i++) {
		cin >> guest[i];
		guest[i] += guest[i - 1];
	}

	cin >> maxGuest;

	for (i = 1; i <= 3; i++) {
		for (j = i * maxGuest; j <= n; j++) {
			dp[i][j] = max(dp[i][j - 1], dp[i - 1][j - maxGuest] + (guest[j] - guest[j - maxGuest]));
		}
	}

	cout << dp[3][n];

	return 0;
}
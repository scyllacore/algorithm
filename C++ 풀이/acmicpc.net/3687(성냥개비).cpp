#include <iostream>
#include <algorithm>

using namespace std;

#define SIZE 100

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	int matchStick[9] = { 0,0,1,7,4,2,0,8,10 };
	long long dp[SIZE + 1] = { 0 };

	for (int i = 0; i < 9; i++) {
		dp[i] = matchStick[i];
	}

	dp[6] = 6;

	for (int i = 9; i <= SIZE; i++) {
		dp[i] = dp[i - 2] * 10 + matchStick[2];

		for (int j = 3; j <= 7; j++) {
			dp[i] = min(dp[i - j] * 10 + matchStick[j], dp[i]);
		}
	}

	int tc;
	cin >> tc;

	int n;
	for (; tc--;) {

		cin >> n;

		cout << dp[n] << ' ';

		if (n % 2 == 0) {
			for (int i = 0; i < n / 2; i++) {
				cout << 1;
			}
		}
		else {
			cout << 7;
			for (int i = 0; i < (n - 3) / 2; i++) {
				cout << 1;
			}
		}


		cout << '\n';
	}


}
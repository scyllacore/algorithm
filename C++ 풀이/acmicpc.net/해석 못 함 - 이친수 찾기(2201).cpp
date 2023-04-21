#include <iostream>

using namespace std;

#define MAX (int)88

unsigned long long dp[MAX + 1] = { 0,1,1 };
unsigned long long dpSum[MAX + 1] = { 0,1,2 };

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	unsigned long long k;
	cin >> k;

	if (k == 1) {
		cout << 1;
		return 0;
	}

	for (int i = 3; i <= MAX; i++) {
		dp[i] = dp[i - 1] + dp[i - 2];
		dpSum[i] = dp[i] + dpSum[i - 1];
	}

	int n;
	for (n = 2; dpSum[n] < k; n++) {}

	k -= (dpSum[n - 1] + 1);
	n--;

	cout << 1;

	for (; n > 0;) {
		if (k > dpSum[n - 1]) {
			cout << 1;
			k -= (dpSum[n - 1] + 1);
		}
		else {
			cout << 0;
		}
		n--;
	}

	return 0;
}

//1779979416004714189
//1000000000000000000
//1100087778366101931
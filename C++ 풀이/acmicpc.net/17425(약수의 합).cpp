#include <iostream>
#include <vector>

#define MAX (int)1e6

using namespace std;

int main() {

	cin.tie(NULL);
	ios::sync_with_stdio(false);

	vector<unsigned long long> divisors(MAX + 1, 1);
	vector<unsigned long long> dp(MAX + 1, 0);

	int i, j;

	dp[1] = 1;

	for (i = 2; i <= MAX; i++) {
		for (j = 1; i * j <= MAX; j++) {
			divisors[i * j] += i;
		}
		dp[i] = dp[i - 1] + divisors[i];
	}


	int tc, n;

	cin >> tc;

	for (; tc--;) {
		cin >> n;
		cout << dp[n] << '\n';
	}

	return 0;
}


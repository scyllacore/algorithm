#include <iostream>
#include <numeric>

using namespace std;

int dp[100001]={0};

int main() {

	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	int n, m;
	cin >> n >> m;

	int i,j;

	for (i = 1; i <= n; i++) {
		cin >> dp[i];
	}

	for (i = 2; i <= n; i++) {
		dp[i] += dp[i-1];
	}


	while (m--) {
		cin >> i >> j;
		cout << dp[j]-dp[i-1] << '\n';

	}

}


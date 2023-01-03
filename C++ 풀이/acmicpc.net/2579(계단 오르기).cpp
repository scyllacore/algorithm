#include <iostream>
#include <algorithm>

using namespace std;

int stair[301] = { 0 };
int dp[301]={0};


int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	int n;
	cin >> n;

	int i;

	for (i = 1; i <= n; i++) {
		cin >> stair[i];
	}

	dp[1] = stair[1];
	dp[2] = stair[2]+ stair[1];


	for (i = 3; i <= n; i++) {
		dp[i] = max(stair[i - 1] + dp[i - 3], dp[i - 2]) + stair[i];
	}

	cout << dp[n];

	return 0;

}
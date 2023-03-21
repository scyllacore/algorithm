#include <iostream>
#include <algorithm>

using namespace std;

struct chartInfo {
	int t, p;
};

chartInfo* chart;

int n;
int maxBenefit = 0;

void dfs(int curT, int sumP) {

	if (curT > n + 1) {
		return;
	}

	maxBenefit = max(sumP, maxBenefit);

	for (int i = curT; i <= n; i++) {
		dfs(i + chart[i].t, sumP + chart[i].p);
	}

}

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> n;

	chart = new chartInfo[n + 1];

	for (int i = 1; i <= n; i++) {
		cin >> chart[i].t >> chart[i].p;
	}

	//1. dfs(1, 0);

	/*
	2.
	int* dp = new int[n + 2]{0,chart[1].p};

	for (int i = 2; i <= n; i++) {
		dp[i] = chart[i].p;
		for (int j = 1; j < i; j++) {
			if (j + chart[j].t <= i) {
				dp[i] = max(dp[j] + chart[i].p, dp[i]);
			}
		}
	}

	for (int i = 1; i <= n; i++) {
		if (i + chart[i].t <= n + 1) {
			maxBenefit = max(dp[i], maxBenefit);
		}
	}

	cout << maxBenefit;
	*/

	int* dp = new int[n + 2]{ 0 };

	for (int i = n; i >= 1; i--) {
		if (i + chart[i].t > n + 1) {
			dp[i] = dp[i + 1];
		}
		else {
			dp[i] = max(chart[i].p + dp[i + chart[i].t], dp[i + 1]);
		}
	}

	cout << dp[1];

}
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {

	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	int n, i, ans;
	cin >> n;

	vector<int> arr(n + 1, 0);
	vector<vector<int>> dp(n + 1, vector<int>(2, 0));


	for (i = 1; i <= n; i++) {
		cin >> arr[i];
	}

	ans = dp[1][0] = arr[1]; // 이 부분 실수
	dp[1][1] = 0;


	for (i = 2; i <= n; i++) {
		dp[i][0] = max(dp[i - 1][0] + arr[i], arr[i]);
		dp[i][1] = max(dp[i - 1][0], dp[i - 1][1] + arr[i]);

		ans = max(max(dp[i][0], dp[i][1]), ans); // 조금 더 압축

	}

	cout << ans;
	return 0;
}
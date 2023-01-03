#include <iostream>
#define max(a,b) a>b?a:b

using namespace std;

int main() {

	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	int n, i, ans;
	cin >> n;

	int* arr = new int[n];
	int* dp = new int[n];


	for (i = 0; i < n; i++) {
		cin >> arr[i];
	}

	ans = dp[0] = arr[0];

	for (i = 1; i < n; i++) {
		dp[i] = max(arr[i], dp[i - 1] + arr[i]);
		ans = max(dp[i], ans);
	}

	cout << ans;

	delete[] arr;
	delete[] dp;

	return 0;

}
#include <iostream>
#include <algorithm>

using namespace std;

int arr[501][501];
int dp[501][501] = { {0} };

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	int n, i, j, maxVal = 0;
	cin >> n;

	for (i = 1; i <= n; i++) {
		for (j = 1; j <= i; j++) {
			cin >> arr[i][j];
		}
	}

	dp[1][1] = arr[1][1];


	for (i = 2; i <= n; i++) {
		for (j = 1; j <= i; j++) {
			dp[i][j] = max(dp[i - 1][j - 1], dp[i - 1][j]) + arr[i][j];
		}
	}

	/*for (i = 1; i <= n; i++) {
		for (j = 1; j <= i; j++) {
			cout << dp[i][j] << ' ';
		}
		cout << '\n';
	}
	*/

	cout << *max_element(&dp[n][1], &dp[n][n + 1]); //�ִ� ã�� �˰���.
	//&dp[n][n] -> &dp[n][n+1]�� �ٲ�. ������ �ε����� ������ ���ϴ� �� ����.


	return 0;

}
#include <iostream>

using namespace std;

int dp[11][221] = { {1} };

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	int n, m, k;
	cin >> n >> m >> k;

	for (int i = 1; i <= n; i++) {
		for (int j = i; j <= m; j++) {
			dp[i][j] = dp[i - 1][j - 1] + dp[i][j - i];
		}
	}

	for (int a = 1; n > 0;) {
		n--, m--;

		for (; k > dp[n][m]; a++) {
			k -= dp[n][m]; // 이 두 줄 이해가 안됨.
			m -= n + 1;
		}

		cout << a << ' ';
	}

	return 0;
}

/*
#include<cstdio>
int dp[11][221] = { 1 }, n, m, k;
int main() {
	scanf("%d %d %d", &n, &m, &k);

	for (int i = 1; i <= n; i++)
		for (int j = i; j <= m; j++)
			dp[i][j] = dp[i][j - i] + dp[i - 1][j - 1];

	for (int i = 0; i <= n; i++) {
		for (int j = 0; j <= m; j++) {
			printf("%d ", dp[i][j]);
		}
		printf("\n");
	}


	for (int i = 1; n > 0;) {
		n--, m--; // 앞에 1을 추가하는 경우를 반영
		for (; k > dp[n][m]; i++) { k -= dp[n][m], m -= n + 1; } //추가한 앞자리를 1씩 늘림.
		printf("%d %d ", n,m);

		printf("%d\n", i);
	}
	return 0;
}


http://codersbrunch.blogspot.com/2015/08/2291-sequence.html
*/
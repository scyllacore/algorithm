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
			k -= dp[n][m]; // �� �� �� ���ذ� �ȵ�.
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
		n--, m--; // �տ� 1�� �߰��ϴ� ��츦 �ݿ�
		for (; k > dp[n][m]; i++) { k -= dp[n][m], m -= n + 1; } //�߰��� ���ڸ��� 1�� �ø�.
		printf("%d %d ", n,m);

		printf("%d\n", i);
	}
	return 0;
}


http://codersbrunch.blogspot.com/2015/08/2291-sequence.html
*/
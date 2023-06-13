#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#define MAXK (int)1e6
#define MAXN (int)100

struct bag {
	int w, v;
};

int dp[MAXN + 1][MAXK + 1] = { {0} };

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	int n, k;
	cin >> n >> k;

	vector<bag> bags(n + 1);

	for (int i = 1; i <= n; i++) {
		cin >> bags[i].w >> bags[i].v;
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= k; j++) {
			dp[i][j] = dp[i - 1][j];
			if (j - bags[i].w >= 0) {
				dp[i][j] = max(dp[i][j], dp[i - 1][j - bags[i].w] + bags[i].v);
			}
		}
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= k; j++) {
			cout << dp[i][j] << ' ';
		}
		cout << '\n';
	}

	cout << dp[n][k];
	return 0;
}
//https://www.acmicpc.net/board/view/92803
/*
1 1 1 1 1 1 1 1 1 1 1 1 1 1 1
1 3 4 4 4 4 4 4 4 4 4 4 4 4 4
1 3 4 4 4 4 6 7 7 7 7 7 7 7 7
1 3 4 4 4 4 6 7 7 7 7 7 8 8 8
1 3 4 5 6 8 9 9 9 9 11 12 12 12 12
1 3 4 5 6 8 9 9 11 12 12 12 12 14 15
1 3 4 5 6 8 9 9 11 12 12 13 14 14 15
1 3 4 5 6 8 9 9 11 12 13 13 15 16 16
1 3 4 5 6 8 9 9 11 12 13 13 15 16 17
1 3 4 5 6 8 9 9 11 12 13 13 15 16 17
17
*/

/*
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#define MAXK (int)1e6
#define MAXN (int)100

struct bag {
	int w, v;
};

int dp[MAXN + 1][MAXK + 1] = { {0} };

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	int n, k;
	cin >> n >> k;

	vector<bag> bags(n + 1);

	for (int i = 1; i <= n; i++) {
		cin >> bags[i].w >> bags[i].v;
	}

	for (int i = 1; i <= n; i++) {
		for (int j = bags[i].w; j <= k; j++) {
			dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - bags[i].w] + bags[i].v);
		}
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= k; j++) {
			cout << dp[i][j] << ' ';
		}
		cout << '\n';
	}

	cout << dp[n][k];
	return 0;
}

1 1 1 1 1 1 1 1 1 1 1 1 1 1 1
0 3 4 4 4 4 4 4 4 4 4 4 4 4 4
0 0 0 0 4 4 6 7 7 7 7 7 7 7 7
0 0 0 0 4 4 6 7 7 7 7 7 8 8 8
0 0 0 5 5 5 6 7 9 9 11 12 12 12 12
0 0 3 5 5 5 8 8 9 9 11 12 12 14 15
0 0 3 5 5 5 8 8 9 10 11 12 12 14 15
0 0 0 5 5 5 8 9 9 10 12 12 13 14 15
0 0 0 5 5 5 8 9 9 10 12 13 13 14 16
0 0 0 5 5 5 8 9 9 10 12 13 13 14 16
16

*/

/*
10 15
1 1
2 3
5 3
5 1
4 5
3 3
3 2
4 4
4 4
4 3
*/
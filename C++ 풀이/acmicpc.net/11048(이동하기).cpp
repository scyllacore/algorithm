#include <iostream>

using namespace std;

int candyMaze[1001][1001]={{0}};

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	int n, m;

	cin >> n >> m;

	int i, j;

	for (i = 1; i <= n; i++) {
		for (j = 1; j <= m; j++) {
			cin >> candyMaze[i][j];
		}
	}

	for (i = 1; i <= n; i++) {
		for (j = 1; j <= m; j++) {
			candyMaze[i][j] += max(max(candyMaze[i][j-1], candyMaze[i-1][j]), candyMaze[i-1][j-1]);
		}
	}

	cout << candyMaze[n][m];

	return 0;

}

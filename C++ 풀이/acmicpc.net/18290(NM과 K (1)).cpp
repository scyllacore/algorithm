#include <iostream>
#include <algorithm>
#include <climits>

using namespace std;

int maxValue = INT_MIN;

int n, m, k;

int board[10][10] = { {0} };
bool visited[10][10] = { {0} };

void dfs(int nextPos, int depth, int sum) {

	if (depth >= k) {
		maxValue = max(sum, maxValue);
		return;
	}

	for (int i = nextPos; i < n * m; i++) {
		int y = i / m;
		int x = i % m;

		if (visited[y][x]) {
			continue;
		}

		if (visited[y - 1][x] || visited[y + 1][x] || visited[y][x - 1] || visited[y][x + 1]) {
			continue;
		}

		visited[y][x] = 1;
		dfs(i + 1, depth + 1, sum + board[y][x]);
		visited[y][x] = 0;
	}


}

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> n >> m >> k;

	int i, j;

	for (i = 0; i < n; i++) {
		for (j = 0; j < m; j++) {
			cin >> board[i][j];
		}
	}

	dfs(0, 0, 0);

	cout << maxValue;

	return 0;

}
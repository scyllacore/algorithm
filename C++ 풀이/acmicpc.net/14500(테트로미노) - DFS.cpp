#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, m;
vector<vector<int>> tetroMap;
int maxVal = -1;
bool visited[510][510] = { {0} };

int dy[4] = { -1, 0, 0, 1 }, dx[4] = { 0, -1, 1, 0 };

int exceptTetro[4][4][2] = {
	{{0, 0}, {0, 1}, {0, 2}, {1, 1}},
	{{0, 0}, {1, 0}, {2, 0}, {1, 1}},
	{{0, 0}, {0, 1}, {0, 2}, {-1, 1}},
	{{0, 0}, {-1, 1}, {0, 1}, {1, 1}},
};

bool isNotTruePos(int y, int x) {
	return y < 0 || y >= n || x < 0 || x >= m;
}

void except(int y, int x) {

	int i, j;
	int sum, cnt;
	int nextY, nextX;

	for (i = 0; i < 4; i++) {
		sum = 0;
		for (j = 0; j < 4; j++) {

			nextY = y + exceptTetro[i][j][0];
			nextX = x + exceptTetro[i][j][1];

			if (isNotTruePos(nextY, nextX)) {
				break;
			}
			sum += tetroMap[nextY][nextX];

		}
		if (j == 4) maxVal = max(maxVal, sum);
	}
}

void dfs(int y, int x, int depth, int sum) {

	if (depth == 4) {
		maxVal = max(maxVal, sum);
		return;
	}

	int nextY, nextX;

	for (int i = 0; i < 4; i++) {
		nextY = y + dy[i];
		nextX = x + dx[i];

		if (isNotTruePos(nextY, nextX) || visited[nextY][nextX]) {
			continue;
		}

		visited[nextY][nextX] = 1;
		dfs(nextY, nextX, depth + 1, sum + tetroMap[nextY][nextX]);
		visited[nextY][nextX] = 0;

	}
}

int main() {

	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> n >> m;

	tetroMap.assign(n, vector<int>(m, 0));

	int i, j;

	for (i = 0; i < n; i++) {
		for (j = 0; j < m; j++) {
			cin >> tetroMap[i][j];
		}
	}

	for (i = 0; i < n; i++) {
		for (j = 0; j < m; j++) {
			visited[i][j] = 1;
			dfs(i, j, 1, tetroMap[i][j]);
			except(i, j);
			visited[i][j] = 0;
		}
	}

	cout << maxVal;
	return 0;
}
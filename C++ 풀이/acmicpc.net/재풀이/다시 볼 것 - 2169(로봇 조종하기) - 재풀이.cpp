#include <iostream>
#include <algorithm>

using namespace std;

#define SIZE 1000
#define BOUNDARY -(int)1e6

int dy[] = { 1,0,0 };
int dx[] = { 0,-1,1 };

int mapNM[SIZE][SIZE];
int dp[SIZE][SIZE][3];
bool visited[SIZE][SIZE] = { {0} };


int n, m;

int dfs(int y, int x, int dir) {
	if (y == n - 1 && x == m - 1) {
		return mapNM[y][x];
	}

	if (dp[y][x][dir] != BOUNDARY) {
		return dp[y][x][dir];
	}

	visited[y][x] = 1;

	for (int i = 0; i < 3; i++) {
		int nextY = y + dy[i];
		int nextX = x + dx[i];

		if (nextY >= n || nextX < 0 || nextX >= m || visited[nextY][nextX]) {
			continue;
		}

		dp[y][x][dir] = max(dfs(nextY, nextX, i) + mapNM[y][x], dp[y][x][dir]);
	}

	visited[y][x] = 0;

	return dp[y][x][dir];
}

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> mapNM[i][j];
		}
	}

	fill(&dp[0][0][0], &dp[SIZE - 1][SIZE - 1][3], BOUNDARY);

	int ans = dfs(0, 0, 0);

	cout << ans;
}
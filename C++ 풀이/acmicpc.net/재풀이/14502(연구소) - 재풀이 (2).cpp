#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

#define SIZE 8

struct pos {
	int y, x;
};

int dir[] = { -1,1,0,0 };

int n, m;
int mapNM[SIZE][SIZE] = { {0} };
bool visited[SIZE][SIZE];

int bfs(int wall1, int wall2, int wall3) {
	mapNM[wall1 / m][wall1 % m] = mapNM[wall2 / m][wall2 % m] = mapNM[wall3 / m][wall3 % m] = 1;

	fill(&visited[0][0], &visited[SIZE - 1][SIZE], 0);

	queue<pos> bfsQ;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (mapNM[i][j] == 2) {
				bfsQ.push({ i,j });
				visited[i][j] = 1;
			}
			if (mapNM[i][j] == 1) {
				visited[i][j] = 1;
			}
		}
	}

	for (; !bfsQ.empty();) {
		pos curP = bfsQ.front();
		bfsQ.pop();

		for (int i = 0; i < 4; i++) {
			int nextY = curP.y + dir[i];
			int nextX = curP.x + dir[3 - i];

			if (nextY < 0 || nextY >= n || nextX < 0 || nextX >= m) {
				continue;
			}

			if (!mapNM[nextY][nextX] && !visited[nextY][nextX]) {
				visited[nextY][nextX] = 1;
				bfsQ.push({ nextY,nextX });
			}
		}
	}

	int count = 0;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (!visited[i][j]) {
				count++;
			}
		}
	}

	mapNM[wall1 / m][wall1 % m] = mapNM[wall2 / m][wall2 % m] = mapNM[wall3 / m][wall3 % m] = 0;

	return count;
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

	int ans = 0;

	for (int i = 0; i < n * m; i++) {
		for (int j = i + 1; j < n * m; j++) {
			for (int k = j + 1; k < n * m; k++) {
				if (!mapNM[i / m][i % m] && !mapNM[j / m][j % m] && !mapNM[k / m][k % m]) {
					ans = max(bfs(i, j, k), ans);
				}
			}
		}
	}

	cout << ans;

	return 0;
}
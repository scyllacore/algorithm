#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

#define SIZE 100

struct pos {
	int y, x;
};

int dir[] = { -1,1,0,0 };

bool mapNM[SIZE][SIZE] = { {0} };
int n, m, k;

int bfs(pos start) {

	queue<pos> bfsQ;

	bfsQ.push(start);
	mapNM[start.y][start.x] = 0;

	int cnt = 1;

	for (; !bfsQ.empty();) {
		int curY = bfsQ.front().y;
		int curX = bfsQ.front().x;
		bfsQ.pop();

		for (int i = 0; i < 4; i++) {
			int nextY = curY + dir[i];
			int nextX = curX + dir[3 - i];

			if (nextY < 0 || nextY >= n || nextX < 0 || nextX >= m) {
				continue;
			}

			if (mapNM[nextY][nextX]) {
				mapNM[nextY][nextX] = 0;
				bfsQ.push({ nextY,nextX });
				cnt++;
			}
		}
	}

	return cnt;
}

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> n >> m >> k;

	int r, c;
	for (int i = 0; i < k; i++) {
		cin >> r >> c;
		mapNM[r - 1][c - 1] = 1;
	}

	int ans = 0;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (mapNM[i][j]) {
				ans = max(bfs({ i, j }), ans);
			}
		}
	}

	cout << ans;
	return 0;
}
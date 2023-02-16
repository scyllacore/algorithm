#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

struct pos {
	int y, x;
};

int dy[] = { -1,1,0,0 };
int dx[] = { 0,0,-1,1 };

int m, n;
int area[1000][1000];

queue<pos> bfsQ;

void bfs() {

	for (; !bfsQ.empty();) {
		int curY = bfsQ.front().y;
		int curX = bfsQ.front().x;
		bfsQ.pop();

		for (int i = 0; i < 4; i++) {
			int nextY = curY + dy[i];
			int nextX = curX + dx[i];

			if (nextY < 0 || nextY >= n || nextX < 0 || nextX >= m) {
				continue;
			}

			if (!area[nextY][nextX]) {
				area[nextY][nextX] = area[curY][curX] + 1;
				bfsQ.push({ nextY,nextX });
			}
		}


	}

}

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> m >> n;

	int i, j;

	for (i = 0; i < n; i++) {
		for (j = 0; j < m; j++) {
			cin >> area[i][j];
			if (area[i][j] == 1) {
				bfsQ.push({ i,j });
			}
		}
	}

	bfs();

	int answer = 0;

	for (i = 0; i < n; i++) {
		for (j = 0; j < m; j++) {
			if (area[i][j] == 0) {
				cout << -1;
				return 0;
			}
			answer = max(area[i][j], answer);
		}
	}

	cout << answer - 1;
}
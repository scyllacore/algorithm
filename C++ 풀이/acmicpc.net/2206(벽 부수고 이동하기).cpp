#include <iostream>
#include <queue>
#define MAX 1001

using namespace std;

bool mapNM[MAX][MAX];
int visited[MAX][MAX][2] = { {{0}} };

struct pos {
	int y, x;
	bool wall;
};

int dy[4] = { -1,1,0,0 };
int dx[4] = { 0,0,-1,1 };


int n, m;

int BFS() {

	queue<pos> bfsQ;

	visited[1][1][0] = 1;
	bfsQ.push({ 1,1,0 });

	int curY, curX;
	bool curW;
	int nextY, nextX;
	int i;

	while (!bfsQ.empty()) {

		curY = bfsQ.front().y;
		curX = bfsQ.front().x;
		curW = bfsQ.front().wall;
		bfsQ.pop();

		if (curY == n && curX == m) { return visited[n][m][curW]; }

		for (i = 0; i < 4; i++) {

			nextY = curY + dy[i];
			nextX = curX + dx[i];

			if (nextY <1 || nextY > n || nextX < 1 || nextX > m) {
				continue;
			}

			if (mapNM[nextY][nextX] && !visited[nextY][nextX][!curW] && !curW) {
				visited[nextY][nextX][!curW] = visited[curY][curX][curW] + 1;
				bfsQ.push({ nextY,nextX, !curW });
			}
			else if (!mapNM[nextY][nextX] && !visited[nextY][nextX][curW]) {
				visited[nextY][nextX][curW] = visited[curY][curX][curW] + 1;
				bfsQ.push({ nextY,nextX, curW });
			}

		}

	}


	return -1;

}

int main() {

	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> n >> m;

	int i, j;
	char ch;

	for (i = 1; i <= n; i++) {
		for (j = 1; j <= m; j++) {
			cin >> ch;
			if (ch == '1') { mapNM[i][j] = 1; }
		}
	}

	cout << BFS();

	return 0;
}


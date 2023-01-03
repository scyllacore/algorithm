#include <iostream>
#include <queue>

using namespace std;

bool mapNM[1000][1000];
bool visited[1000][1000][11];
int n, m, k;

struct pos {
	int y, x;
	int wall;
	int move;
};

int dy[4] = { -1,1,0,0 };
int dx[4] = { 0,0,-1,1 };


int bfs() {

	queue<pos> bfsQ;
	bfsQ.push({ 0,0,0,0 });
	visited[0][0][0] = 1;

	int curY,curX,curW,curM;
	int nextY,nextX;
	int i;

	while (!bfsQ.empty()) {
		curY = bfsQ.front().y;
		curX = bfsQ.front().x;
		curW = bfsQ.front().wall;
		curM = bfsQ.front().move;
		bfsQ.pop();

		if (curY == n - 1 && curX == m - 1) { return curM + 1; }

		for (i = 0; i < 4; i++) {
			nextY = curY + dy[i];
			nextX = curX + dx[i];

			if (nextY < 0 || nextY >= n || nextX < 0 || nextX >= m) { continue; }

			if (!mapNM[nextY][nextX] && !visited[nextY][nextX][curW]) {
				visited[nextY][nextX][curW] = 1;
				bfsQ.push({ nextY,nextX,curW,curM + 1});
			}
			else if (mapNM[nextY][nextX] && !visited[nextY][nextX][curW + 1] && curW < k && curM % 2 == 0) {
				visited[nextY][nextX][curW + 1] = 1;
				bfsQ.push({ nextY,nextX,curW + 1,curM + 1 });
			}
			else if (curM % 2 == 1) {
				bfsQ.push({ curY,curX,curW,curM + 1 });
			}
		}

	}

	return -1;
}

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> n >> m >> k;

	int i, j;
	string str;

	for (i = 0; i < n; i++) {
		cin >> str;
		for (j = 0; j < m; j++) {
			if (str[j] == '1') mapNM[i][j] = 1;
		}
	}

	cout << bfs();

	return 0;

}
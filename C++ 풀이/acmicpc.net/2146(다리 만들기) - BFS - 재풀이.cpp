#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

struct pos {
	int y, x;
};

int dy[] = { -1,1,0,0 };
int dx[] = { 0,0,-1,1 };

int n;

bool mapNN[100][100];

int area[100][100] = { {0} };
int areaN = 1;

int dis[100][100] = { {0} };


void bfsArea(int y, int x) {
	queue<pos> bfsQ;
	area[y][x] = -1;
	bfsQ.push({ y,x });

	for (; !bfsQ.empty();) {
		int curY = bfsQ.front().y;
		int curX = bfsQ.front().x;
		bfsQ.pop();

		//area[curY][curX] = -1; 여기있으면 안됨.

		for (int i = 0; i < 4; i++) {
			int nextY = curY + dy[i];
			int nextX = curX + dx[i];

			if (nextY < 0 || nextY >= n || nextX < 0 || nextX >= n) {
				continue;
			}

			if (!mapNN[nextY][nextX]) {
				area[curY][curX] = areaN;
				continue;
			}

			if (mapNN[nextY][nextX] && area[nextY][nextX] == 0) {
				area[nextY][nextX] = -1;
				bfsQ.push({ nextY,nextX });
			}
		}
	}

}

int bfsDis() {

	int result = (int)1e6;

	queue<pos> bfsQ;
	int i, j;

	for (i = 0; i < n; i++) {
		for (j = 0; j < n; j++) {
			if (area[i][j] >= 1) {
				bfsQ.push({ i,j });
			}
		}
	}

	for (; !bfsQ.empty();) {
		int curY = bfsQ.front().y;
		int curX = bfsQ.front().x;
		bfsQ.pop();


		for (int i = 0; i < 4; i++) {
			int nextY = curY + dy[i];
			int nextX = curX + dx[i];

			if (nextY < 0 || nextY >= n || nextX < 0 || nextX >= n) {
				continue;
			}

			if (!area[nextY][nextX]) {
				area[nextY][nextX] = area[curY][curX];
				dis[nextY][nextX] = dis[curY][curX] + 1;
				bfsQ.push({ nextY,nextX });
			}
			else if (area[nextY][nextX] >= 1 && area[nextY][nextX] != area[curY][curX]) { // -1이 존재함을 잊으면 안된다.
				result = min(dis[nextY][nextX] + dis[curY][curX], result);
			}
		}
	}

	return result;

}


int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> n;

	int i, j;

	for (i = 0; i < n; i++) {
		for (j = 0; j < n; j++) {
			cin >> mapNN[i][j];
		}
	}

	for (i = 0; i < n; i++) {
		for (j = 0; j < n; j++) {
			if (mapNN[i][j] && !area[i][j]) {
				bfsArea(i, j);
				areaN++;
			}
		}
	}

	cout << bfsDis();

	return 0;
}
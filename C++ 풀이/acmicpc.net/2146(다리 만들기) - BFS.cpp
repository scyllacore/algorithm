#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

int mapNN[100][100];
int dis[100][100];
int n,ans=99999;

struct pos {
	int y, x;
};
int dy[] = { -1,1,0,0 };
int dx[] = { 0,0,-1,1};


void areaBFS(int y,int x,int area) {

	queue<pos> bfsQ;

	bfsQ.push({ y,x });
	mapNN[y][x] = area;

	int curY, curX;
	int nextY, nextX;
	int i;

	while (!bfsQ.empty()) {

		curY = bfsQ.front().y;
		curX = bfsQ.front().x;
		bfsQ.pop();

		for (i = 0; i < 4; i++) {
			nextY = curY + dy[i];
			nextX = curX + dx[i];

			if (nextY < 0 || nextY >= n || nextX < 0 || nextX >= n)
				continue;

			if (mapNN[nextY][nextX] == -1) {
				mapNN[nextY][nextX] = area;
				bfsQ.push({ nextY,nextX });
			}


		}


	}

}

void BFS() {

	queue<pos> bfsQ;
	int i, j;

	for (i = 0; i < n; i++) {
		for (j = 0; j < n; j++) {
			if (mapNN[i][j] > 0) {
				bfsQ.push({ i,j });
			}
		}
	}

	int curY, curX;
	int nextY, nextX;

	while (!bfsQ.empty()) {

		curY = bfsQ.front().y;
		curX = bfsQ.front().x;
		bfsQ.pop();

		for (i = 0; i < 4; i++) {
			nextY = curY + dy[i];
			nextX = curX + dx[i];

			if (nextY < 0 || nextY >= n || nextX < 0 || nextX >= n)
				continue;

			if (mapNN[nextY][nextX] == 0) {
				mapNN[nextY][nextX] = mapNN[curY][curX];
				dis[nextY][nextX] = dis[curY][curX] + 1;
				bfsQ.push({ nextY,nextX });
			}
			else if(mapNN[nextY][nextX] != mapNN[curY][curX]) {
				ans = min(dis[nextY][nextX] + dis[curY][curX], ans);
			}

		}

	}


}

int main() {

	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	fill(&mapNN[0][0], &mapNN[99][100], 0);
	fill(&dis[0][0], &dis[99][100], 0);


	cin >> n;

	int i, j,tmp;

	for (i = 0; i < n; i++) {
		for (j = 0; j < n; j++) {
			cin >> tmp;
			if(tmp == 1) {
				mapNN[i][j] = -1;
			}
		}
	}

	int area = 1;

	for (i = 0; i < n; i++) {
		for (j = 0; j < n; j++) {
			if (mapNN[i][j] == -1) {
				areaBFS(i,j,area++);
			}
		}
	}


	BFS();

	cout << ans;

}

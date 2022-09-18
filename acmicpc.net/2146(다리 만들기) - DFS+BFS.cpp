#include <iostream>
#include <algorithm>
#include <cstdio>
#include <queue>

using namespace std;

int map[101][101] = { {0} };
int visited[101][101] = { {0} };
int shortDis[101][101] = { {0} };
queue<pair<int, int>> disBFS;

int ans = 99999;

int dy[4] = { -1,1,0,0 };
int dx[4] = { 0,0,-1,1 };

int areaN = 1;

int n;

void DFS_btrk(int y, int x) {

	int i, newY, newX;

	visited[y][x] = -1; // 2. 이곳에 배치해도 된다. 핵심은 현재 지점을 안에 부분으로 가정한다.


	for (i = 0; i < 4; i++) {
		newY = y + dy[i];
		newX = x + dx[i];

		if (newY >= 1 && newY <= n && newX >= 1 && newX <= n) {

			if (!map[newY][newX]) { // 3. 다음 방문 구간 중 0이 존재한다면 현재 위치를 테두리로 취급해야 한다.
				visited[y][x] = areaN;
				//break; 4. 이건 안 된다. 구역을 정해주는 역할을 재귀가 담당하는데 break가 걸리면 재귀가 돌지 않아 구역이 제대로 나눠지지 않는다.
			}
			else if (map[newY][newX] && visited[newY][newX] == 0) { // 이 외에 방문 지점은 넓이 부분 
				//visited[newY][newX] = -1; 1. 이곳에 배치해도 되고
				DFS_btrk(newY, newX);
			}
		}

	}
}

void BFS() {

	int i, newY, newX, y, x;

	while (!disBFS.empty()) {

		y = disBFS.front().first;
		x = disBFS.front().second;
		int spot = visited[y][x];

		disBFS.pop();

		for (i = 0; i < 4; i++) {

			newY = y + dy[i];
			newX = x + dx[i];

			if (newY >= 1 && newY <= n && newX >= 1 && newX <= n)
			{
				if (visited[newY][newX] == 0) {
					visited[newY][newX] = spot;
					shortDis[newY][newX] = shortDis[y][x] + 1;
					disBFS.push(make_pair(newY, newX));
				}
				else if (visited[newY][newX] >= 1 && spot != visited[newY][newX]) {
					ans = min(shortDis[y][x] + shortDis[newY][newX], ans);
				}
			}
		}


	}

}


int main() {

	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> n;

	int i, j;

	for (i = 1; i <= n; i++) {
		for (j = 1; j <= n; j++) {
			cin >> map[i][j];
		}
	}

	for (i = 1; i <= n; i++) {
		for (j = 1; j <= n; j++) {
			if (visited[i][j] || !map[i][j]) continue;

			visited[i][j] = areaN;
			DFS_btrk(i, j);
			areaN++;

		}
	}

	/*for (i = 1; i <= n; i++) {
		for (j = 1; j <= n; j++) {

			cout << visited[i][j] << ' ';
		}
		cout << '\n';
	}*/


	for (i = 1; i <= n; i++) {
		for (j = 1; j <= n; j++) {

			if (visited[i][j] < 1) continue;

			disBFS.push(make_pair(i, j));

		}
	}

	BFS();

	cout << ans; // 찾자 마자 끝내면 안된다. 그 외 안 찾은 부분에서 최소 거리가 있을 수 있기 때문이다.


	return 0;

}
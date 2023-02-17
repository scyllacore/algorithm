#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

struct pos {
	int y, x;
};

int dy[] = { -1,1,0,0 };
int dx[] = { 0,0,-1,1 };

int mapNN[100][100];

int n;
int area = 1;

int mapDis[100][100];

void dfs(int y, int x) {

	for (int i = 0; i < 4; i++) {

		int nextY = y + dy[i];
		int nextX = x + dx[i];

		if (nextY < 0 || nextY >= n || nextX < 0 || nextX >= n) {
			continue;
		}

		if (mapNN[nextY][nextX] == 0) {
			mapNN[y][x] = area;
		}

		if (mapNN[nextY][nextX] == -1) {
			dfs(nextY, nextX);
		}
	}

}

int bfs(queue<pos>& bfsQ) {
	int answer = (int)1e5;

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

			if (mapNN[nextY][nextX] == -1) { // -1구역은 거쳐가면 안된다. 아래 조건에서 문제가 된다.
				continue;
			}

			if (!mapNN[nextY][nextX] && mapDis[nextY][nextX]) {//(+) && mapDis[nextY][nextX], (full) !mapNN[nextY][nextX] && !mapDis[nextY][nextX] -> !(mapNN[nextY][nextX] | mapDis[nextY][nextX])
				mapDis[nextY][nextX] = mapDis[curY][curX] + 1;
				mapNN[nextY][nextX] = mapNN[curY][curX];
				bfsQ.push({ nextY,nextX });
			}
			else if (mapNN[nextY][nextX] != mapNN[curY][curX]) {
				answer = min(mapDis[nextY][nextX] + mapDis[curY][curX], answer);
			}

		}
	}

	return answer;
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
			if (mapNN[i][j]) {
				mapNN[i][j] = -1;
			}
		}
	}

	for (i = 0; i < n; i++) {
		for (j = 0; j < n; j++) {
			if (mapNN[i][j] == -1) {
				dfs(i, j);
				area++;
			}
		}
	}

	queue<pos> bfsQ;

	for (i = 0; i < n; i++) {
		for (j = 0; j < n; j++) {
			if (mapNN[i][j] > 0) {
				bfsQ.push({ i,j });
			}
		}
	}

	cout << bfs(bfsQ);

	return 0;
}
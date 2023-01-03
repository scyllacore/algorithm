#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;


int dz[6] = { 0,0,0,0,-1,1 };
int dy[6] = { -1,1,0,0,0,0 };
int dx[6] = { 0,0,-1,1,0,0 };

struct tomatoPos {
	int z, y, x;
};

int m, n, h;
int tomato[100][100][100];
queue<tomatoPos> goodTomato;


void BFS() {

	int z, y, x;
	int i;
	int nextZ, nextY, nextX;

	while (!goodTomato.empty()) {

		z = goodTomato.front().z;
		y = goodTomato.front().y;
		x = goodTomato.front().x;
		goodTomato.pop();

		for (i = 0; i < 6; i++) {
			nextZ = z + dz[i];
			nextY = y + dy[i];
			nextX = x + dx[i];

			if (nextZ >= 0 && nextZ < h && nextY >= 0 && nextY < n && nextX >= 0 && nextX < m) {
				if (tomato[nextZ][nextY][nextX] == 0) {
					tomato[nextZ][nextY][nextX] = tomato[z][y][x] + 1;
					goodTomato.push({ nextZ,nextY,nextX });
				}
			}

		}

	}

}



int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> m >> n >> h;

	int i, j, k;

	for (k = 0; k < h; k++) {
		for (i = 0; i < n; i++) {
			for (j = 0; j < m; j++) {
				cin >> tomato[k][i][j];
				if (tomato[k][i][j] == 1) {
					goodTomato.push({ k, i, j });
				}
			}
		}
	}

	BFS();


	int ans = 0;

	for (k = 0; k < h; k++) {
		for (i = 0; i < n; i++) {
			for (j = 0; j < m; j++) {
				if (tomato[k][i][j] == 0) {
					cout << -1;
					return 0;
				}
				ans = max(tomato[k][i][j], ans);
			}
		}
	}

	cout << ans - 1;

	return 0;
}


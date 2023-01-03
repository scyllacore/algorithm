#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

int box[1001][1001] = { {0} };

int m, n;
int dy[4] = { -1,1,0,0 };
int dx[4] = { 0,0,-1,1 };

queue<pair<int, int>> nodeBFS;

void BFS() {

	int i;
	int nextX, nextY;
	int x, y;

	while (!nodeBFS.empty()) {
		y = nodeBFS.front().first;
		x = nodeBFS.front().second;

		for (i = 0; i < 4; i++) {
			nextY = y + dy[i];
			nextX = x + dx[i];

			if (nextY >= 1 && nextY <= n && nextX >= 1 && nextX <= m) {

				if (box[nextY][nextX] == 0) {
					box[nextY][nextX] = box[y][x]+1;
					nodeBFS.push(make_pair(nextY, nextX));
				}
			}

		}
		nodeBFS.pop();
	}

}

int main() {

	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> m >> n;

	int i, j;

	for (i = 1; i <= n; i++) {
		for (j = 1; j <= m; j++) {
			cin >> box[i][j];
			if (box[i][j] == 1) {
				nodeBFS.push(make_pair(i, j));
			}
		}
	}

	BFS();
	
	int ans = 0;

	for (i = 1; i <= n; i++) {
		for (j = 1; j <= m; j++) {
			if (box[i][j] == 0) {
				cout << -1;
				return	0;
			}
			ans = max(box[i][j], ans);
		}
	}

	cout << ans - 1;

	return 0;

}
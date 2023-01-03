#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

int dy[4] = { -1,1,0,0 };
int dx[4] = { 0,0,-1,1 };

struct pos {
	int y, x;
};

int n, m;
int map[8][8];
int sequence[8];
int ans=0;

void BFS() {

	int i, j;
	int seqVal; // sequenceVal
	int mapTmp[8][8];

	for (i = 0; i < n; i++) {
		copy(&map[i][0], &map[i][m], &mapTmp[i][0]);
	}

	for (i = 0; i < 3; i++) {
		seqVal = sequence[i];
		mapTmp[seqVal / m][seqVal % m] = 1;
	}

	queue<pos> bfsQ;

	int zeroCnt = 0;

	for (i = 0; i < n; i++) {
		for (j = 0; j < m; j++) {
			if (mapTmp[i][j] == 2) {
				bfsQ.push({ i,j });
			}
			else if(mapTmp[i][j] == 0) {
				zeroCnt++;
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

			if (nextY < 0 || nextY >= n || nextX < 0 || nextX >= m) {
				continue;
			}

			if (!mapTmp[nextY][nextX]) {
				mapTmp[nextY][nextX] = 2;
				bfsQ.push({ nextY,nextX });
				zeroCnt--;
			}


		}

	}

	ans = max(zeroCnt, ans);

}

void DFS(int start,int depth) {

	int i;

	if (depth >= 3) {
		BFS();
		return;
	}

	
	for (i = start; i < n * m; i++) {

		if (map[i / m][i % m] != 0) {
			continue;
		}

		sequence[depth] = i;
		DFS(i + 1, depth + 1);
	}



}

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> n >> m;

	int i,j;

	for (i = 0; i < n; i++) {
		for (j = 0; j < m; j++) {
			cin >> map[i][j];
		}
	}

	DFS(0,0);

	cout << ans;

}
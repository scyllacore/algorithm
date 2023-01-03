#include <iostream>
#include <algorithm>

using namespace std;

int n;
int mapNN[100][100];
bool visited[100][100];

int dy[4] = { -1,1,0,0 };
int dx[4] = { 0,0,-1,1 };


void DFS_btrk(int curY, int curX) {

	int i;
	int nextY, nextX;

	visited[curY][curX] = 1;

	for (i = 0; i < 4; i++) {
		nextY = curY + dy[i];
		nextX = curX + dx[i];

		if (nextY < 0 || nextY >= n || nextX < 0 || nextX >= n || visited[nextY][nextX]) continue;

		DFS_btrk(nextY, nextX);
	}


}

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> n;

	int i, j,maxH=0;

	for (i = 0; i < n; i++) {
		for (j = 0; j < n; j++) {
			cin >> mapNN[i][j];
			maxH = max(mapNN[i][j], maxH);
		}
	}

	int ans = 1;

	for (int h= 1; h <= maxH; h++) {

		fill(&visited[0][0], &visited[99][100], 0);

		int cnt = 0;

		for (i = 0; i < n; i++) {
			for (j = 0; j < n; j++) {
				visited[i][j] = (mapNN[i][j] <= h) ? 1:0;
			}
		}

		for (i = 0; i < n; i++) {
			for (j = 0; j < n; j++) {
				if (!visited[i][j]) {
					DFS_btrk(i,j);
					cnt++;
				}
			}
		}

		ans = max(cnt, ans);

	}

	cout << ans;

	return 0;

}
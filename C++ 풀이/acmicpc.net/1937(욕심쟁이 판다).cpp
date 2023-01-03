#include <iostream>
#include <algorithm>

using namespace std;

int n;
int forest[500][500] = { {0} };
int dp[500][500] = { {0} };

int dy[] = { -1,1,0,0 };
int dx[] = { 0,0,-1,1 };

int DFS_btrk(int y, int x) {

	if (dp[y][x]) return dp[y][x];

	dp[y][x] = 1;

	int nY, nX;

	for (int i = 0; i < 4; i++) {

		nY = y + dy[i];
		nX = x + dx[i];

		if (nY < 0 || nY >= n || nX < 0 || nX >= n) continue;

		if (forest[nY][nX] > forest[y][x]) {
			dp[y][x] = max(DFS_btrk(nY, nX) + 1, dp[y][x]);
		}

	}

	return dp[y][x];

}


int main() {

	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> n;

	int i, j;

	for (i = 0; i < n; i++) {
		for (j = 0; j < n; j++) {
			cin >> forest[i][j];
		}
	}

	int ans = 1;

	for (i = 0; i < n; i++) {
		for (j = 0; j < n; j++) {
			ans = max(DFS_btrk(i, j), ans);
		}
	}

	cout << ans;
	
	return 0;

}


#include <iostream>
#include <numeric>
#include <vector>

using namespace std;

#define SIZE 16 + 1

vector<vector<vector<int>>> dir = { {{0,1},{1,1}},{{1,0},{1,1}},{{0,1},{1,0},{1,1}} };

int dp[SIZE][SIZE][3] = { {{0}} };
bool mapNN[SIZE][SIZE] = { {0} };

int n;

int dfs(int y, int x, int d) {

	if (y == n && x == n) {
		return 1;
	}

	if (dp[y][x][d] != -1) {
		return dp[y][x][d];
	}

	dp[y][x][d] = 0;

	/*
	for (int i = 0; i < dir[d].size(); i++) {
		for (int j = 0; j < dir[d][i].size(); j++) {
	*/

	for (int i = 0; i < dir[d].size(); i++) {
		int nextY = y + dir[d][i][0];
		int nextX = x + dir[d][i][1];
		int nextDir = dir[d][i][0] * (dir[d][i][1] + 1);

		if (nextY < 1 || nextY > n || nextX < 1 || nextX > n) {
			continue;
		}

		if (mapNN[nextY][nextX]) {
			continue;
		}

		if (nextDir == 2 && (mapNN[nextY - 1][nextX] || mapNN[nextY][nextX - 1])) {
			continue;
		}

		dp[y][x][d] += dfs(nextY, nextX, nextDir);
	}

	return dp[y][x][d];

}

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> n;

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> mapNN[i][j];
		}
	}

	fill(&dp[0][0][0], &dp[SIZE - 1][SIZE - 1][SIZE], -1);

	cout << dfs(1, 2, 0);
	return 0;
}


/*
#include <iostream>
#include <numeric>

using namespace std;

#define SIZE 16 + 1

int dp[SIZE][SIZE][3] = { {{0}} };
bool mapNN[SIZE][SIZE] = { {0} };


int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	int n;
	cin >> n;

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> mapNN[i][j];
		}
	}

	dp[1][2][0] = 1;

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (mapNN[i][j] || (i==1 && j<3)) {
				continue;
			}

			if (!mapNN[i][j - 1]) {
				dp[i][j][0] = dp[i][j - 1][0] + dp[i][j - 1][2];
			}

			if (!mapNN[i - 1][j]) {
				dp[i][j][1] = dp[i - 1][j][1] + dp[i - 1][j][2];
			}

			if (!mapNN[i][j - 1] && !mapNN[i - 1][j]) {
				dp[i][j][2] = dp[i - 1][j - 1][0] + dp[i - 1][j - 1][1] + dp[i - 1][j - 1][2];
			}
		}
	}

	cout << accumulate(&dp[n][n][0], &dp[n][n][3], 0);
	return 0;
}
*/
#include <iostream>
#include <algorithm>

using namespace std;

#define SIZE 500

int dir[] = { -1,1,0,0 };

int n;
int dp[SIZE + 1][SIZE + 1] = { {0} };
int mapNN[SIZE + 1][SIZE + 1] = { {0} };


int dfs(int y, int x) {

	if (dp[y][x] != 0) {
		return dp[y][x];
	}

	dp[y][x] = 1;

	for (int i = 0; i < 4; i++) {

		int nextY = y + dir[i];
		int nextX = x + dir[3 - i];

		if (nextY < 0 || nextY >= n || nextX < 0 || nextX >= n) {
			continue;
		}

		if (mapNN[nextY][nextX] > mapNN[y][x]) {
			dp[y][x] = max(dfs(nextY, nextX) + 1, dp[y][x]);
		}

	}

	return dp[y][x];
}

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> n;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> mapNN[i][j];
		}
	}

	int ans = 0;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			ans = max(dfs(i, j), ans);
		}
	}

	cout << ans;

	return 0;
}

/*
#include <iostream>
#include <algorithm>

using namespace std;

#define SIZE 500

int dir[] = { -1,1,0,0 };

int n;
int dp[SIZE + 1][SIZE + 1] = { {0} };
int mapNN[SIZE + 1][SIZE + 1] = { {0} };


int dfs(int y, int x) {

	if (dp[y][x] != 0) {
		return dp[y][x];
	}

	dp[y][x] = 1;

	for (int i = 0; i < 4; i++) {

		int nextY = y + dir[i];
		int nextX = x + dir[3 - i];

		if (nextY < 0 || nextY >= n || nextX < 0 || nextX >= n) {
			continue;
		}

		if (mapNN[nextY][nextX] > mapNN[y][x]) {
			dp[y][x] = max(dfs(nextY, nextX) + 1, dp[y][x]);
		}

	}

	return dp[y][x];
}

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> n;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> mapNN[i][j];
		}
	}

	int ans = 0;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			ans = max(dfs(i, j), ans);
		}
	}

	cout << ans;

	return 0;
}*/


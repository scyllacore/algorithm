#include <iostream>
#include <algorithm>

using namespace std;

#define SIZE 10

int n;

int mapNN[SIZE][SIZE] = { {0} };
bool visited[SIZE][SIZE] = { {0} };

int dir[] = { -1,1,0,0 };

int ans = (int)1e5;

bool isNotPossibleSpot(int& curY, int& curX) {

	if (visited[curY][curX]) {
		return 1;
	}

	for (int i = 0; i < 4; i++) {
		int nextY = curY + dir[i];
		int nextX = curX + dir[3 - i];

		if (nextY < 0 || nextY >= n || nextX < 0 || nextX >= n) {
			return 1;
		}

		if (visited[nextY][nextX]) {
			return 1;
		}
	}

	return 0;
}

void setVisited(int curY, int curX, int flag) {
	visited[curY][curX] = 1 - flag;

	for (int i = 0; i < 4; i++) {
		int nextY = curY + dir[i];
		int nextX = curX + dir[3 - i];

		visited[nextY][nextX] = 1 - flag;
	}
}

int getFlowerCost(int curY, int curX) {
	int sum = 0;

	sum += mapNN[curY][curX];

	for (int i = 0; i < 4; i++) {
		int nextY = curY + dir[i];
		int nextX = curX + dir[3 - i];

		sum += mapNN[nextY][nextX];
	}

	return sum;
}

void dfs(int curSpot, int cost, int depth) {
	if (depth >= 3) {
		ans = min(cost, ans);
		return;
	}

	for (int i = curSpot; i < SIZE * SIZE; i++) {
		int curY = i / n;
		int curX = i % n;

		if (isNotPossibleSpot(curY, curX)) {
			continue;
		}

		setVisited(curY, curX, 0);
		dfs(i + 1, cost + getFlowerCost(curY, curX), depth + 1);
		setVisited(curY, curX, 1);
	}
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

	dfs(0, 0, 0);

	cout << ans;

	return 0;
}
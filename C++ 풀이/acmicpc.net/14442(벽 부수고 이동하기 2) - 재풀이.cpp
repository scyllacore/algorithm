#include <iostream>
#include <queue>

using namespace std;

#define MAX (int)1e3
#define MAX_K 11 // 10으로 해도 테케는 통과한다.

struct spotInfo {
	int y, x;
	int movingCount;
	int breakCount;
};

int dir[] = { -1,1,0,0 };

int n, m, k;

bool visited[MAX][MAX][MAX_K] = { {{0}} };
bool mapNM[MAX][MAX] = { {0} };

int bfs() {

	queue<spotInfo> bfsQ;
	bfsQ.push({ 0,0,1,0 });
	visited[0][0][0] = 1;

	for (; !bfsQ.empty();) {
		int curY = bfsQ.front().y;
		int curX = bfsQ.front().x;
		int curMovingCount = bfsQ.front().movingCount;
		int curBreakCount = bfsQ.front().breakCount;
		bfsQ.pop();

		if (curY == n - 1 && curX == m - 1) {
			return curMovingCount;
		}

		for (int i = 0; i < 4; i++) {
			int nextY = curY + dir[i];
			int nextX = curX + dir[3 - i];
			int nextMovingCount = curMovingCount + 1;
			int breakWallCount = curBreakCount + 1;

			if (nextY < 0 || nextY >= n || nextX < 0 || nextX >= m) {
				continue;
			}

			if (!mapNM[nextY][nextX] && !visited[nextY][nextX][curBreakCount]) {
				visited[nextY][nextX][curBreakCount] = 1;
				bfsQ.push({ nextY,nextX,nextMovingCount,curBreakCount });
			}
			else if (mapNM[nextY][nextX]
				&& breakWallCount <= k && !visited[nextY][nextX][breakWallCount]) {
				visited[nextY][nextX][breakWallCount] = 1;
				bfsQ.push({ nextY,nextX,nextMovingCount,breakWallCount });
			}
		}

	}

	return -1;
}

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> n >> m >> k;

	string tmp;

	for (int i = 0; i < n; i++) {
		cin >> tmp;
		for (int j = 0; j < m; j++) {
			if (tmp[j] == '1') {
				mapNM[i][j] = 1;
			}
		}
	}

	cout << bfs();

	return 0;
}
#include <iostream>
#include <queue>

using namespace std;

#define MAX 1000
#define BREAK_WALL 1

struct posInfo {
	int y, x;
	bool wallFlag;
	int moveCnt;
};

int dir[] = { -1,1,0,0 };
int n, m;

bool mapNM[MAX][MAX];
bool visited[MAX][MAX][2] = { {{0}} };

int bfs() {

	queue<posInfo> bfsQ;
	bfsQ.push({ 0,0,0,1 });
	visited[0][0][0] = 1;

	for (; !bfsQ.empty();) {
		int curY = bfsQ.front().y;
		int curX = bfsQ.front().x;
		int curMoveCnt = bfsQ.front().moveCnt;
		bool curWallFlag = bfsQ.front().wallFlag;
		bfsQ.pop();

		if (curY == n - 1 && curX == m - 1) {
			return curMoveCnt;
		}

		for (int i = 0; i < 4; i++) {
			int nextY = curY + dir[i];
			int nextX = curX + dir[3 - i];

			if (nextY < 0 || nextY >= n || nextX < 0 || nextX >= m) {
				continue;
			}

			if (!mapNM[nextY][nextX] && !visited[nextY][nextX][curWallFlag]) {
				visited[nextY][nextX][curWallFlag] = 1;
				bfsQ.push({ nextY,nextX,curWallFlag,curMoveCnt + 1 });
			}
			else if (mapNM[nextY][nextX] && !curWallFlag && !visited[nextY][nextX][BREAK_WALL]) { // !curWallFlag(이전에 벽을 안 부셨을 때만) !visited[nextY][nextX][BREAK_WALL](해당 벽을 부수는 케이스에 접근이 가능하다)  
				visited[nextY][nextX][BREAK_WALL] = 1;
				bfsQ.push({ nextY,nextX,BREAK_WALL,curMoveCnt + 1 });
			}
		}

	}

	return -1;
}

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> n >> m;

	string tmp;
	for (int i = 0; i < n; i++) {
		cin >> tmp;
		for (int j = 0; j < m; j++) {
			mapNM[i][j] = (tmp[j] - '0');
		}
	}

	cout << bfs();
	return 0;

}
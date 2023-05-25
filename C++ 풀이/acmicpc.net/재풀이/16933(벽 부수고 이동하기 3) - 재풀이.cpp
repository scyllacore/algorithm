#include <iostream>
#include <queue>

using namespace std;

#define MAX (int)1e3
#define MAX_K 11

struct spotInfo {
	int y, x;
	int movingCount;
	int breakCount;
	bool dayNight;
};

int dir[] = { -1,1,0,0 };

bool mapNM[MAX][MAX] = { {0} };
bool visited[MAX][MAX][MAX_K] = { {{0}} };

int n, m, k;

int bfs() {

	queue<spotInfo> bfsQ;
	bfsQ.push({ 0,0,1,0,0 });
	visited[0][0][0] = 1;

	for (; !bfsQ.empty();) {
		int curY = bfsQ.front().y;
		int curX = bfsQ.front().x;
		int curMovingCount = bfsQ.front().movingCount;
		int curBreakCount = bfsQ.front().breakCount;
		int curDayNight = bfsQ.front().dayNight; // 밤낮 상태를 따로 지정해뒀지만 사실 movingCount를 통해 밤낮 상태를 확인할 수 있다.
		bfsQ.pop();

		//cout << curY << ' ' << curX << ' ' << curMovingCount << ' ' << curBreakCount << ' ' << curDayNight << '\n';

		if (curY == n - 1 && curX == m - 1) {
			return curMovingCount;
		}
		/*	밤일 때는 다음 이동공간이 벽인지도 확인해야함으로 여기서 이동 여부를 확인할 수 없다.
		if (curDayNight) {
			bfsQ.push({ curY,curX,curMovingCount+1,curBreakCount,!curDayNight });
			continue;
		}*/

		int nextMovingCount = curMovingCount + 1;
		int nextBreakCount = curBreakCount + 1;
		bool nextDayNight = 1 - curDayNight;

		for (int i = 0; i < 4; i++) {
			int nextY = curY + dir[i];
			int nextX = curX + dir[3 - i];

			if (nextY < 0 || nextY >= n || nextX < 0 || nextX >= m) {
				continue;
			}

			if (!mapNM[nextY][nextX] && !visited[nextY][nextX][curBreakCount]) {
				visited[nextY][nextX][curBreakCount] = 1;
				bfsQ.push({ nextY,nextX,nextMovingCount,curBreakCount,nextDayNight });
			}
			else if (mapNM[nextY][nextX]
				&& nextBreakCount <= k && !visited[nextY][nextX][nextBreakCount] // 실수1. nextMovingCount <= k로 잘못씀
				&& !curDayNight) {
				visited[nextY][nextX][nextBreakCount] = 1;
				bfsQ.push({ nextY,nextX,nextMovingCount,nextBreakCount,nextDayNight });
			}
			else if (mapNM[nextY][nextX] && curDayNight) {
				bfsQ.push({ curY,curX,nextMovingCount,curBreakCount,nextDayNight });
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

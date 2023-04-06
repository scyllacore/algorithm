#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

#define INF (int)1e5
#define MAX 100

#define DOWN 0
#define UP 1
#define RIGHT 2
#define LEFT 3

#define DIR_TYPE 4

struct spotInfo {
	int y, x;
	int dir;
};

int dir[] = { -1,1,0,0 };

vector<vector<char>> board;
int w, h;
int visited[MAX][MAX][DIR_TYPE];

bool isFalseSpot(int y, int x) {
	return y < 0 || y >= h || x < 0 || x >= w || board[y][x] == '*';
}

int bfs(spotInfo& start, spotInfo& end) {

	fill(&visited[0][0][0], &visited[MAX - 1][MAX - 1][DIR_TYPE], INF);

	queue<spotInfo> bfsQ;

	for (int i = 0; i < DIR_TYPE; i++) {

		visited[start.y][start.x][i] = 0;

		int nextY = start.y + dir[i];
		int nextX = start.x + dir[3 - i];

		if (isFalseSpot(nextY, nextX)) { //  || board[y][x] == '*' 오류1. 이 조건 빼먹어서 isFalseSpot에 추가하였음.
			continue;
		}

		visited[nextY][nextX][i] = 0;
		bfsQ.push({ nextY,nextX,i });
	}

	for (; !bfsQ.empty();) {
		int curY = bfsQ.front().y;
		int curX = bfsQ.front().x;
		int curDir = bfsQ.front().dir;

		int curMirrorCount = visited[curY][curX][curDir];
		bfsQ.pop();

		for (int i = 0; i < DIR_TYPE; i++) {
			int nextY = curY + dir[i];
			int nextX = curX + dir[3 - i];
			int nextDir = i;
			int nextMirrorCount = curMirrorCount;

			if (isFalseSpot(nextY, nextX)) { // 오류2. visited[nextY][nextX][i] != INF 방문처리 여기서 하면 안됨.
				continue;
			}

			if ((curDir <= 1 && nextDir >= 2)
				|| (curDir >= 2 && nextDir <= 1)) {
				nextMirrorCount++;
			}

			if (nextMirrorCount < visited[nextY][nextX][nextDir]) {
				visited[nextY][nextX][nextDir] = nextMirrorCount;
				bfsQ.push({ nextY,nextX,nextDir });
			}
		}
	}

	return *min_element(&visited[end.y][end.x][0], &visited[end.y][end.x][DIR_TYPE]);
}

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> w >> h;

	board.assign(h, vector<char>(w));

	vector<spotInfo> cSpot;

	string tmp;

	for (int i = 0; i < h; i++) {
		cin >> tmp;
		for (int j = 0; j < w; j++) {
			board[i][j] = tmp[j];

			if (board[i][j] == 'C') {
				cSpot.push_back({ i,j,-1 });
				board[i][j] = '.';
			}
		}
	}

	cout << bfs(cSpot[0], cSpot[1]);

	return 0;
}
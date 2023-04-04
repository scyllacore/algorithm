#include <iostream>
#include <queue>
#include <string>

using namespace std;

#define MAX 100

#define DOWN 0
#define UP 1
#define RIGHT 2
#define LEFT 3
#define NOT_DIFINE_DIR -1

int dir[] = { -1,1,0,0 };

struct spotInfo {
	int y, x;
	int moveDir;
	int moveCount;
	int mirror;
};

vector<vector<char>> board;
int w, h;

bool visited[MAX][MAX] = { {0} };

struct cmp {
	bool operator()(spotInfo& s1, spotInfo& s2) {
		//if (s1.mirror != s2.mirror) {
		return s1.mirror > s2.mirror;
		//}

		//return s1.moveCount > s2.moveCount;
	}
};

int bfs(spotInfo& start, spotInfo& end) {
	priority_queue<spotInfo, vector<spotInfo>, cmp> bfsQ;
	bfsQ.push({ start.y,start.x,NOT_DIFINE_DIR,0,-1 });
	bfsQ.push({ start.y,start.x,NOT_DIFINE_DIR,0,-1 });
	bfsQ.push({ start.y,start.x,NOT_DIFINE_DIR,0,-1 });
	bfsQ.push({ start.y,start.x,NOT_DIFINE_DIR,0,-1 });

	//cout << start.y << ' ' << start.x << "\n";
	//cout << end.y << ' ' << end.x << "\n\n";

	visited[start.y][start.x] = 1;

	for (; !bfsQ.empty();) {
		int curY = bfsQ.top().y;
		int curX = bfsQ.top().x;
		int curMoveDir = bfsQ.top().moveDir;
		int curMoveCount = bfsQ.top().moveCount;
		int curMirror = bfsQ.top().mirror;
		bfsQ.pop();

		//cout << curY << ' ' << curX << ' ' << curMoveDir << ' ' << curMoveCount << ' ' << curMirror << '\n';

		if (curY == end.y && curX == end.x)
		{
			return curMirror;
		}

		for (int i = 0; i < 4; i++) {
			int nextY = curY + dir[i];
			int nextX = curX + dir[3 - i];

			if (nextY < 0 || nextY >= h || nextX < 0 || nextX >= w) {
				continue;
			}

			if (board[nextY][nextX] == '.' && !visited[nextY][nextX] && i == curMoveDir) {
				visited[nextY][nextX] = 1;
				bfsQ.push({ nextY,nextX,curMoveDir,curMoveCount + 1,curMirror });
			}
			if (board[nextY][nextX] == '.' && !visited[nextY][nextX] && i != curMoveDir) {
				visited[nextY][nextX] = 1;
				bfsQ.push({ nextY,nextX,i,curMoveCount + 1,curMirror + 1 });
			}
		}
	}

	return -1;
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
				cSpot.push_back({ i,j,0,0,0 });
				board[i][j] = '.';
			}
		}
	}

	cout << bfs(cSpot[0], cSpot[1]);

	return 0;
}

//0 12
//4 12
//4 13
//9 13
//9 5
//8 5

//cur : 2 12 2 3 1
//next : 3 12 1 4 2

//https://bingorithm.tistory.com/2
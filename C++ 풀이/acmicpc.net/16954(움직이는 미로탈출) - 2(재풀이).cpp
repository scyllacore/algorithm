#include <iostream>
#include <queue>
#include <vector>

using namespace std;

#define MAX 8

struct pos {
	int y, x;
	int t;
};

int dy[] = { -1,-1,-1,0,0,0,1,1,1 };
int dx[] = { -1,0,1,-1,0,1,-1,0,1 };

vector<string> board(MAX);

int visited[MAX][MAX] = { {0} };

void moveDown() {

	string dot = "........";

	for (int i = MAX - 1; i > 0; i--) {
		board[i] = board[i - 1];
	}

	board[0] = dot;
}

bool bfs() {
	queue<pos> bfsQ;
	bfsQ.push({ MAX - 1,0,1 });
	visited[MAX - 1][0] = 1;

	int curTime = 1;

	for (; !bfsQ.empty();) {
		int curY = bfsQ.front().y;
		int curX = bfsQ.front().x;
		int curT = bfsQ.front().t;
		bfsQ.pop();

		if (curY == 0 && curX == MAX - 1) {
			return 1;
		}

		if (curTime != curT) {
			moveDown();
			curTime = curT;
		}

		if (board[curY][curX] == '#') { //½Ç¼ö1. »©¸ÔÀ½, ½Ç¼ö2. ¼ø¼­ ¸ÂÃç¾ßµÊ. curT if À§¿¡´Ù°¡ ¾¸.
			continue;
		}

		for (int i = 0; i <= MAX; i++) {
			int nextY = curY + dy[i];
			int nextX = curX + dx[i];
			int nextT = curT + 1;

			if (nextY < 0 || nextY >= MAX || nextX < 0 || nextX >= MAX) {
				continue;
			}

			if (visited[nextY][nextX] == nextT) {
				continue;
			}

			if (board[nextY][nextX] == '.') {
				visited[nextY][nextX] = nextT;
				bfsQ.push({ nextY,nextX,nextT });
			}

		}

	}

	return 0;
}

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	for (int i = 0; i < MAX; i++) {
		cin >> board[i];
	}

	cout << bfs();

	return 0;
}
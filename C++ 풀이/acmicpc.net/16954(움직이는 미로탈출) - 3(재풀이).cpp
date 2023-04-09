#include <iostream>
#include <vector>
#include <queue>

using namespace std;

#define MAX 8

struct posInfo {
	int y, x;
	int t;
};

int dy[] = { -1,-1,-1,0,0,0,1,1,1 }; // 실수1. 대각선 방향까지 포함.
int dx[] = { -1,0,1,-1,0,1,-1,0,1 };

bool visited[MAX][MAX][MAX + 1]; // 원래는 int형으로 선언하고 idx안에다 초값을 넣는 형태로 풀었다.

void move(vector<string>& board) {

	string dotLine = "........";

	for (int i = 7; i > 0; i--) {
		board[i] = board[i - 1];
	}

	board[0] = dotLine;
}

bool bfs(vector<string>& board) {

	queue<posInfo> bfsQ;
	bfsQ.push({ 7,0,0 });
	visited[7][0][0] = 1;

	int t = 0;

	for (; !bfsQ.empty();) {
		int curY = bfsQ.front().y;
		int curX = bfsQ.front().x;
		int curT = bfsQ.front().t;
		bfsQ.pop();

		if (t != curT) {
			move(board);
			t = curT;
		}

		if (board[curY][curX] == '#') {
			continue;
		}

		if (curT >= 8) {
			return 1;
		}

		for (int i = 0; i < 9; i++) {
			int nextY = curY + dy[i];
			int nextX = curX + dx[i];
			int nextT = curT + 1;

			if (nextY < 0 || nextY >= MAX || nextX < 0 || nextX >= MAX) {
				continue;
			}

			if (board[nextY][nextX] == '.' && !visited[nextY][nextX][nextT]) { // int로 처리시 visited[nextY][nextX] = nextT;
				visited[nextY][nextX][nextT] = 1;
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

	vector<string> board(MAX);

	string line;

	for (int i = 0; i < MAX; i++) {
		cin >> board[i];
	}

	cout << bfs(board);
	return 0;
}
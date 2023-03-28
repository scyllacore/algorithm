#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

struct pos {
	int y, x;
};

int dy[] = { -1,1,0,0 };
int dx[] = { 0,0,-1,1 };

int n, m;
vector<vector<int>> board;

int sequence[3] = { 0 };

int answer = 0;

int bfs(vector<vector<int>> newBoard) {

	for (int i = 0; i < 3; i++) {
		int y = sequence[i] / m;
		int x = sequence[i] % m;

		newBoard[y][x] = 1;
	}

	queue<pos> bfsQ;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (newBoard[i][j] == 2) {
				bfsQ.push({ i,j });
			}
		}
	}

	for (; !bfsQ.empty();) {
		int curY = bfsQ.front().y;
		int curX = bfsQ.front().x;
		bfsQ.pop();

		for (int i = 0; i < 4; i++) {
			int nextY = curY + dy[i];
			int nextX = curX + dx[i];

			if (nextY < 0 || nextY >= n || nextX < 0 || nextX >= m) {
				continue;
			}

			if (!newBoard[nextY][nextX]) {
				newBoard[nextY][nextX] = 2;
				bfsQ.push({ nextY,nextX });
			}
		}
	}

	int zeroCnt = 0;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (!newBoard[i][j]) {
				zeroCnt++;
			}
		}
	}

	return zeroCnt;
}

void dfs(int start, int depth) {
	if (depth >= 3) {
		answer = max(bfs(board), answer);
		return;
	}

	for (int i = start; i < n * m; i++) { // i = 0  조심해야한다.
		int y = i / m;
		int x = i % m;

		if (board[y][x] != 0) {
			continue;
		}

		sequence[depth] = i;
		dfs(i + 1, depth + 1);
	}
}

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> n >> m;

	board.assign(n, vector<int>(m));

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> board[i][j];
		}
	}

	dfs(0, 0);

	cout << answer;
	return 0;

}
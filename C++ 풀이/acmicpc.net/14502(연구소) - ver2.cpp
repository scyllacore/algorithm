#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int dy[4] = { -1,1,0,0 };
int dx[4] = { 0,0,-1,1 };

struct pos {
	int y, x;
};

int n, m;
vector<vector<int>> board;
int sequence[3];
int ans = 0;

int BFS(vector<vector<int>> newBoard) {

	int i, j;
	int seqVal; // sequenceVal

	for (i = 0; i < 3; i++) {
		seqVal = sequence[i];
		newBoard[seqVal / m][seqVal % m] = 1;
	}

	queue<pos> bfsQ;

	for (i = 0; i < n; i++) {
		for (j = 0; j < m; j++) {
			if (newBoard[i][j] == 2) {
				bfsQ.push({ i,j });
			}
		}
	}

	int curY, curX;
	int nextY, nextX;

	while (!bfsQ.empty()) {

		curY = bfsQ.front().y;
		curX = bfsQ.front().x;
		bfsQ.pop();

		for (i = 0; i < 4; i++) {
			nextY = curY + dy[i];
			nextX = curX + dx[i];

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

	for (i = 0; i < n; i++) {
		for (j = 0; j < m; j++) {
			if (newBoard[i][j] == 0) {
				zeroCnt++;
			}
		}
	}

	return zeroCnt;
}

void DFS(int start, int depth) {

	int i;

	if (depth >= 3) {
		ans = max(BFS(board), ans);
		return;
	}


	for (i = start; i < n * m; i++) {

		if (board[i / m][i % m] != 0) {
			continue;
		}

		sequence[depth] = i;
		DFS(i + 1, depth + 1);
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

	DFS(0, 0);

	cout << ans;
	return 0;
}
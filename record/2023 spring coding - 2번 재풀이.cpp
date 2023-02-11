#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int n = 6, m = 8;

struct pos {
	int y, x;
};

int dy[] = { -1,-1,-1,0,0,1,1,1 };
int dx[] = { -1,0,1,-1,1,-1,0,1 };

int tmpDy[] = { -1,1,0,0 };
int tmpDx[] = { 0,0,-1,1 };

bool visited[1000][1000] = { {0} };
bool tmpBoard[1002][1002] = { {0} };

int bfs(int y, int x, vector<string>& board) {

	fill(&tmpBoard[0][0], &tmpBoard[1001][1002], 0);

	queue<pos> bfsQ;
	bfsQ.push({ y,x });
	tmpBoard[y + 1][x + 1] = visited[y][x] = 1;

	int curY, curX;

	int cnt = 1;

	for (; !bfsQ.empty();) {
		curY = bfsQ.front().y;
		curX = bfsQ.front().x;
		bfsQ.pop();

		for (int i = 0; i < 8; i++) {
			int nextY = curY + dy[i];
			int nextX = curX + dx[i];

			if (nextY < 0 || nextY >= n || nextX < 0 || nextX >= m) {
				continue;
			}

			if (!visited[nextY][nextX] && board[nextY][nextX] == 'o') {
				tmpBoard[nextY + 1][nextX + 1] = visited[nextY][nextX] = 1;
				bfsQ.push({ nextY,nextX });
				cnt++;
			}
		}

	}

	for (int i = 0; i <= n + 1; i++) {
		for (int j = 0; j <= m + 1; j++) {
			cout << tmpBoard[i][j];
		}
		cout << '\n';
	}
	cout << cnt << '\n';

	bfsQ.push({ 0, 0 });
	tmpBoard[0][0] = 1;

	for (; !bfsQ.empty();) {
		curY = bfsQ.front().y;
		curX = bfsQ.front().x;
		//cout << curY << ' ' << curX << '\n';
		bfsQ.pop();

		for (int i = 0; i < 4; i++) {
			int nextY = curY + tmpDy[i];
			int nextX = curX + tmpDx[i];

			if (nextY < 0 || nextY > n + 1 || nextX < 0 || nextX > m + 1) {
				continue;
			}

			if (!tmpBoard[nextY][nextX]) {
				tmpBoard[nextY][nextX] = 1;
				bfsQ.push({ nextY,nextX });
			}
		}

	}

	for (int i = 0; i <= n + 1; i++) {
		for (int j = 0; j <= m + 1; j++) {
			cout << tmpBoard[i][j];
		}
		cout << '\n';
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			if (!tmpBoard[i][j]) {
				visited[i-1][j-1] = 1;
				cnt++;
			}
		}
	}

	cout << cnt << '\n';

	return cnt;

}

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);


	vector<string> board = {
	"xxxxxooo",
	"xxooxxox",
	"xoxooxxo",
	"xoxoxoxx",
	"xxoxxoxx",
	"xoxooxxx"
	};

	int answer = 0;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (!visited[i][j] && board[i][j] == 'o') {
				answer += bfs(i, j, board);
			}
		}
	}

	cout << '\n';

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cout << visited[i][j];
		}
		cout << '\n';
	}


	cout << answer;

	return 0;

}
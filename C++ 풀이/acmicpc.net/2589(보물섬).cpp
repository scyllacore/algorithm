#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

#define MAX 50

struct pos {
	int y, x;
};

int dir[] = { -1,1,0,0 };

int n, m;
vector<string> board;
int visited[MAX][MAX];

int bfs(pos start) {
	fill(&visited[0][0], &visited[MAX - 1][MAX], -1);

	queue<pos> bfsQ;
	visited[start.y][start.x] = 0;
	bfsQ.push(start);

	int maxMove = 0;

	for (; !bfsQ.empty();) {
		int curY = bfsQ.front().y;
		int curX = bfsQ.front().x;
		bfsQ.pop();

		for (int i = 0; i < 4; i++) {
			int nextY = curY + dir[i];
			int nextX = curX + dir[3 - i];

			if (nextY < 0 || nextY >= n || nextX < 0 || nextX >= m) {
				continue;
			}

			if (board[nextY][nextX] != 'L') {
				continue;
			}

			if (visited[nextY][nextX] == -1) {
				visited[nextY][nextX] = visited[curY][curX] + 1;
				bfsQ.push({ nextY,nextX });
				maxMove = max(visited[nextY][nextX], maxMove);
			}
		}
	}

	return maxMove;
}

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> n >> m;

	board.assign(n, "");

	for (int i = 0; i < n; i++) {
		cin >> board[i];
	}

	int ans = 0;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (board[i][j] == 'L') {
				ans = max(bfs({ i,j }), ans);
			}
		}
	}

	cout << ans;
	return 0;
}
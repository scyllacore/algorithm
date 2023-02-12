#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, m, k;

int dy[] = { 0,1,0,-1 };
int dx[] = { 1,0,-1,0 };

vector<vector<int>> board;

void rotate(int start, int len) {
	int rotationCnt = k % len;

	for (int i = 0; i < rotationCnt; i++) {

		int startVal = board[start][start];
		int y = start, x = start;

		for (int j = 0; j < 4;) {
			int newY = y + dy[j];
			int newX = x + dx[j];

			if (newY >= start && newY < n - start && newX >= start && newX < m - start) {
				board[y][x] = board[newY][newX];
				y = newY;
				x = newX;
			}
			else {
				j++;
			}
		}

		board[start + 1][start] = startVal;
	}

}

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> n >> m >> k;

	board.assign(n, vector<int>(m));

	int i, j;

	for (i = 0; i < n; i++) {
		for (j = 0; j < m; j++) {
			cin >> board[i][j];
		}
	}

	int cnt = min(n, m) / 2;

	for (i = 0; i < cnt; i++) {
		rotate(i, 2 * (n - 2 * i) + 2 * (m - 2 * i) - 4);
	}

	for (i = 0; i < n; i++) {
		for (j = 0; j < m; j++) {
			cout << board[i][j] << ' ';
		}
		cout << '\n';
	}

	return 0;

}
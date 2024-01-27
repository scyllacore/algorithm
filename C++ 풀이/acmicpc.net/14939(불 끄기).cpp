#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#define INF (int)1e3

int dy[] = { 0, -1,1,0,0 };
int dx[] = { 0,0,0,-1,1 };

void click(vector<string>& tmpBoard, int y, int x) {
	for (int i = 0; i < 5; i++) {
		int nY = y + dy[i];
		int nX = x + dx[i];

		if (nY < 0 || nY >= 10 || nX < 0 || nX >= 10) {
			continue;
		}

		tmpBoard[nY][nX] = (tmpBoard[nY][nX] == '#') ? 'O' : '#';
	}
}

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	vector<string> board(10);

	for (int i = 0; i < 10; i++) {
		cin >> board[i];
	}

	vector<string> tmpBoard;

	int ans = INF;

	for (int i = 0; i < (1 << 10); i++) {
		tmpBoard = board;

		int cnt = 0;

		for (int j = 0; j < 10; j++) {
			if (i & (1 << j)) {
				click(tmpBoard, 0, j);
				cnt++;
			}
		}

		for (int j = 0; j < 9; j++) {
			for (int k = 0; k < 10; k++) {
				if (tmpBoard[j][k] == 'O') {
					click(tmpBoard, j + 1, k);
					cnt++;
				}
			}
		}

		bool flag = 1;

		for (int j = 0; j < 10; j++) {
			if (tmpBoard[9][j] == 'O') {
				flag = 0;
				break;
			}
		}

		if (flag) {
			ans = min(ans, cnt);
		}

	}

	cout << (ans == INF ? -1 : ans);
	return 0;
}
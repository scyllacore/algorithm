#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

int n, m, k;

int board[300][300];

void rotateBoard() {
	int i, j;

	int cnt = min(n, m) / 2;

	for (i = 0; i < cnt; i++) {

		int tmp = board[i][i];

		for (j = i; j < m - i - 1; j++) {
			board[0 + i][j] = board[0 + i][j + 1];
		}

		for (j = i + 1; j < n - i; j++) {
			board[j - 1][m - 1 - i] = board[j][m - 1 - i];
		}

		for (j = m - 1 - i - 1; j >= i; j--) {
			board[n - 1 - i][j + 1] = board[n - 1 - i][j];
		}

		for (j = n - 1 - i - 1; j >= i + 1; j--) {
			board[j + 1][0 + i] = board[j][0 + i];
		}

		board[i + 1][i] = tmp;

	}

}

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> n >> m >> k;

	int i, j;

	for (i = 0; i < n; i++) {
		for (j = 0; j < m; j++) {
			cin >> board[i][j];
		}
	}

	for (; k--;) {
		rotateBoard();
	}

	for (i = 0; i < n; i++) {
		for (j = 0; j < m; j++) {
			cout << board[i][j] << ' ';
		}
		cout << '\n';
	}

	return 0;

}
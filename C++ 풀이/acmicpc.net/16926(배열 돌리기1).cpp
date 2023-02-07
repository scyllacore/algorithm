#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int n, m, k;

void rotateBoard(vector<vector<int>>& board) {
	int i, j;

	int cnt = min(n, m) / 2;

	for (i = 0; i < cnt; i++) {

		queue<int> q;

		//for (j = 0; j < m - i; j++) {
		//	q.push(board[0 + i][j + i]);
		//}

		//for (j = 0; j < n - i; j++) {
		//	q.push(board[j + i][m - 1 - i]);
		//}

		//for (j = m - 1 - i; j >= 0; j--) { // 
		//	q.push(board[n - 1 - i][j - i]);
		//}

		//for (j = n - 1 - i; j >= 0; j--) {
		//	q.push(board[j - i][0 + i]);
		//}

		for (j = i; j < m - i; j++) {
			q.push(board[0 + i][j]);
		}

		for (j = i + 1; j < n - i; j++) {
			q.push(board[j][m - 1 - i]);
		}

		for (j = m - 1 - i - 1; j >= i; j--) {
			q.push(board[n - 1 - i][j]);
		}

		for (j = n - 1 - i - 1; j >= i + 1; j--) {
			q.push(board[j][0 + i]);
		}


		q.push(q.front());
		q.pop();

		/*for (j = 0; j < q.size(); j++) {
			cout << q.front() << ' ';
			q.push(q.front());
			q.pop();
		}
		cout << '\n';*/

		for (j = i; j < m - i; j++) {
			board[0 + i][j] = q.front();
			q.pop();
		}

		for (j = i + 1; j < n - i; j++) {
			board[j][m - 1 - i] = q.front();
			q.pop();
		}

		for (j = m - 1 - i - 1; j >= i; j--) {
			q.push(board[n - 1 - i][j]);
			board[n - 1 - i][j] = q.front();
			q.pop();
		}

		for (j = n - 1 - i - 1; j >= i + 1; j--) {
			board[j][0 + i] = q.front();
			q.pop();
		}

	}

}

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> n >> m >> k;

	vector<vector<int>> board(n, vector<int>(m));

	int i, j;

	for (i = 0; i < n; i++) {
		for (j = 0; j < m; j++) {
			cin >> board[i][j];
		}
	}

	for (; k--;) {
		rotateBoard(board);
	}

	for (i = 0; i < n; i++) {
		for (j = 0; j < m; j++) {
			cout << board[i][j] << ' ';
		}
		cout << '\n';
	}

	return 0;

}
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	string board;

	vector<vector<char>> boardV;

	for (;;) {
		cin >> board;

		if (board[0] == 'e') {
			break;
		}

		boardV.assign(3, vector<char>(3, '.'));

		int countO = 0, countX = 0;

		for (int i = 0; i < board.length(); i++) {
			boardV[i / 3][i % 3] = board[i];
			if (board[i] == 'O') {
				countO++;
			}
			else if (board[i] == 'X') {
				countX++;
			}
		}

		if ((countO + countX) % 2 == 0) {
			if (countO != countX) {
				cout << "invalid" << '\n';
				continue;
			}
		}
		else {
			if (countO > countX) {
				cout << "invalid" << '\n';
				continue;
			}
		}

		if (countO + countX == 9) {
			cout << "valid" << '\n';
			continue;
		}

		bool checkTic = 0;

		int rowCount, colCount;

		for (int i = 0; i < 3; i++) {
			rowCount = 1, colCount = 1;

			for (int j = 1; j < 3; j++) {
				if (boardV[i][j] != '.' && boardV[i][0] == boardV[i][j]) {
					rowCount++;
				}
				if (boardV[j][i] != '.' && boardV[0][i] == boardV[j][i]) {
					colCount++;
				}
			}

			if (rowCount == 3 || colCount == 3) {
				checkTic = 1;
				break;
			}
		}

		int leftCrossCount = 1, rightCrossCount = 1;

		for (int i = 1; i < 3; i++) {
			if (boardV[i][i] != '.' && boardV[0][0] == boardV[i][i]) {
				leftCrossCount++;
			}
			if (boardV[2 - i][2 - i] != '.' && boardV[2][2] == boardV[2 - i][2 - i]) {
				rightCrossCount++;
			}
		}

		if (leftCrossCount == 3 || rightCrossCount == 3) {
			checkTic = 1;
		}

		if (!checkTic) {
			cout << "invalid" << '\n';
			continue;
		}

		cout << "valid" << '\n';
	}

	return 0;
}
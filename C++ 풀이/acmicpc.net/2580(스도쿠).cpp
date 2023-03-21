#include <iostream>
#include <vector>

using namespace std;

struct pos {
	int y, x;
};

vector<pos> zeroPos;
int sudoku[9][9];


void DFS_btrk(int cnt) {

	int i, j;

	if (cnt >= zeroPos.size()) {
		for (i = 0; i < 9; i++) {
			for (j = 0; j < 9; j++) {
				cout << sudoku[i][j] << ' ';
			}
			cout << '\n';
		}
		exit(0);
	}

	int sudokuVal[10] = { 0 };

	int y = zeroPos[cnt].y;
	int x = zeroPos[cnt].x;

	for (i = 0; i < 9; i++) {
		sudokuVal[sudoku[y][i]]++;
		sudokuVal[sudoku[i][x]]++;
	}

	for (i = (y / 3) * 3; i < (y / 3) * 3 + 3; i++) {
		for (j = (x / 3) * 3; j < (x / 3) * 3 + 3; j++) {
			sudokuVal[sudoku[i][j]]++;
		}
	}

	for (i = 1; i <= 9; i++) {
		if (!sudokuVal[i]) {
			sudoku[y][x] = i;
			DFS_btrk(cnt + 1);
			sudoku[y][x] = 0;
		}
	}

}

int main() {

	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	int i, j;

	for (i = 0; i < 9; i++) {
		for (j = 0; j < 9; j++) {
			cin >> sudoku[i][j];

			if (!sudoku[i][j]) {
				zeroPos.push_back({ i,j });
			}

		}
	}

	DFS_btrk(0);

	return 0;
}

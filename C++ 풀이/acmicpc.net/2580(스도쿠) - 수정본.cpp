#include <iostream>
#include <vector>

using namespace std;

struct pos {
	int y, x;
};

vector<pos> zeroPos;
int sudoku[9][9];

void print() {
	int i, j;
	for (i = 0; i < 9; i++) {
		for (j = 0; j < 9; j++) {
			cout << sudoku[i][j] << ' ';
		}
		cout << '\n';
	}
}

bool check(int y, int x, int n) {

	int i, j;

	for (i = 0; i < 9; i++) {
		if (sudoku[y][i] == n) return 0;
		if (sudoku[i][x] == n) return 0;
	}

	for (i = (y / 3) * 3; i < (y / 3) * 3 + 3; i++) {
		for (j = (x / 3) * 3; j < (x / 3) * 3 + 3; j++) {
			if (sudoku[i][j] == n) return 0;
		}
	}

	return 1;

}

void DFS_btrk(int cnt) {

	int i, j;

	if (cnt >= zeroPos.size()) {
		print();
		exit(0);
	}

	int y = zeroPos[cnt].y, x = zeroPos[cnt].x;

	for (i = 1; i <= 9; i++) {
		if (check(y, x, i)) {
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

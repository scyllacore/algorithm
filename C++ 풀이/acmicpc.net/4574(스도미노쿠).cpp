#include <iostream>
#include <vector>

using namespace std;

struct pos {
	int y, x;
};

int dy[] = { 1,0 };
int dx[] = { 0,1 };

vector<pos> zeroPos;
int sudoku[9][9] = { {0} };
bool visited[10][10] = { {0} };

int tcNum = 1;
bool finish = 0;

bool check(int y, int x, int n) {

	int i,j;

	for (i = 0; i < 9; i++) {
		if (sudoku[i][x] == n) return false;
		if (sudoku[y][i] == n) return false;
	}

	for (i = (y / 3) * 3; i < (y / 3) * 3 + 3; i++) {
		for (j = (x / 3) * 3; j < (x / 3) * 3 + 3; j++) {
			if (sudoku[i][j] == n) return false;
		}
	}

	return true;

}

void print() {
	int i, j;
	cout << "Puzzle " << tcNum++ << '\n';

	for (i = 0; i < 9; i++) {
		for (j = 0; j < 9; j++) {
			cout << sudoku[i][j];
		}
		cout << '\n';
	}
}


void DFS_btrk(int cnt) {

	if (finish == 1) {
		return;
	}

	if (cnt >= zeroPos.size()) {

		print();
		finish = 1;

		return;

	}

	int y = zeroPos[cnt].y, x = zeroPos[cnt].x;
	int i, j, k;

	if (!sudoku[y][x]) {
		for (k = 0; k < 2; k++) {

			int nextY = y + dy[k];
			int nextX = x + dx[k];

			if (nextY < 0 || nextY >= 9 || nextX < 0 || nextX >= 9 || sudoku[nextY][nextX]) continue;

			for (i = 1; i <= 9; i++) {
				for (j = 1; j <= 9; j++) {

					if (i == j || visited[i][j]) continue;

					if (check(y, x, i) && check(nextY, nextX, j)) {

						sudoku[y][x] = i;
						sudoku[nextY][nextX] = j;

						visited[i][j] = 1;
						visited[j][i] = 1;

						DFS_btrk(cnt + 1);

						sudoku[y][x] = 0;
						sudoku[nextY][nextX] = 0;

						visited[i][j] = 0;
						visited[j][i] = 0;
					}

				}
			}
		}
	}
	else {
		DFS_btrk(cnt + 1);
	}

}



int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	int n, i, j;
	int u, v;
	string lu, lv, ln;

	for (;;) {
		cin >> n;

		if (n == 0) break;

		for (i = 0; i < n; i++) {
			cin >> u >> lu >> v >> lv;

			sudoku[lu[0] - 'A'][lu[1] - '1'] = u;
			sudoku[lv[0] - 'A'][lv[1] - '1'] = v;

			visited[v][u] = visited[u][v] = 1;


		}

		for (i = 1; i <= 9; i++) {
			cin >> ln;
			sudoku[ln[0] - 'A'][ln[1] - '1'] = i;
		}

		for (i = 0; i < 9; i++) {
			for (j = 0; j < 9; j++) {
				if (!sudoku[i][j]) {
					zeroPos.push_back({ i,j });
				}
			}
		}

		DFS_btrk(0);

		zeroPos.clear();
		fill(&sudoku[0][0], &sudoku[8][9],0);
		fill(&visited[0][0], &visited[9][10], 0);

		finish = 0;

	}

	return 0;

}



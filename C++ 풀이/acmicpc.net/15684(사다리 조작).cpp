#include <iostream>

using namespace std;

bool ladderBoard[31][11];

int n, m, h;
int ladderCnt;

bool DFS_btrk(int row,int depth) {

	int i, j;

	if (depth >= ladderCnt) {

		int pos;

		for (i = 1; i <= n; i++) {

			pos = i;
			for (j = 1; j <= m; j++) {

				if (ladderBoard[j][pos]) {
					pos++;
				}
				else if (pos > 1 && ladderBoard[j][pos - 1]) {
					pos--;
				}
			}
			if (pos != i) { // 각 사다리 케이스에 대해 i로 시작해 i로 도착하는 경우를 모두 만족해야 함.
				return 0;
			}

		}
		return 1;
	}

	for (i = row; i <= m; i++) {
		for (j = 1; j <= n - 1; j++) {
			if (!ladderBoard[i][j - 1] && !ladderBoard[i][j] && !ladderBoard[i][j + 1]) {
				ladderBoard[i][j] = 1;
				if (DFS_btrk(i, depth + 1)) return 1;
				ladderBoard[i][j] = 0;
			}
		}
	}

	return 0;

}

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> n >> h >> m;

	int i;
	int row, col;

	for (i = 0; i < h; i++) {
		cin >> row >> col;
		ladderBoard[row][col] = 1;
	}


	for (i = 0; i <= 3; i++) {
		ladderCnt = i;
		if (DFS_btrk(1, 0)) {
			cout << i;
			return 0;
		}
	}

	cout << -1;

	return 0;


}

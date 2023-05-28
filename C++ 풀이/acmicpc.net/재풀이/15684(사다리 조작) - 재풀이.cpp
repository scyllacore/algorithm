#include <iostream>

using namespace std;

#define SIZE 30

bool ladderBoard[SIZE + 1][SIZE + 1] = { 0 };
int n, h, m;
int ladderCount;

bool dfs(int row, int depth) {

	if (depth > ladderCount) {

		int pos;

		for (int i = 1; i <= n; i++) {
			pos = i;

			for (int j = 1; j <= m; j++) {
				if (ladderBoard[j][pos]) {
					pos++;
				}
				else if (ladderBoard[j][pos - 1]) {
					pos--;
				}
			}

			if (pos != i) {
				return 0;
			}
		}

		return 1;
	}


	for (int i = row; i <= m; i++) {
		for (int j = 1; j < n; j++) {
			if (!ladderBoard[i][j - 1] && !ladderBoard[i][j] && !ladderBoard[i][j + 1]) {
				ladderBoard[i][j] = 1;
				if (dfs(i, depth + 1)) {
					return 1;
				}
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

	int r, c;
	for (int i = 0; i < h; i++) {
		cin >> r >> c;
		ladderBoard[r][c] = 1;
	}


	for (int i = 0; i <= 3; i++) {
		ladderCount = i;
		if (dfs(1, 1)) {
			cout << i;
			return 0;
		}
	}

	cout << -1;

	return 0;
}
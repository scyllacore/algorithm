#include <iostream>
#include <vector>

#define MAX 9 

using namespace std;

struct zeroPos {
	int y, x;
};

vector<zeroPos> zeroInfo;

int board[MAX][MAX] = { {0} };

void print() {
	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			cout << board[i][j] << ' ';
		}
		cout << '\n';
	}
}

bool checkPossibleNumber(int n, int cnt) {

	int y = zeroInfo[cnt].y, x = zeroInfo[cnt].x;

	for (int i = 0; i < 9; i++) { // i : 1~9·Î Àß¸ø ¾¸
		if (board[y][i] == n || board[i][x] == n) {
			return 0;
		}
	}

	for (int i = (y / 3) * 3; i < (y / 3) * 3 + 3; i++) {
		for (int j = (x / 3) * 3; j < (x / 3) * 3 + 3; j++) {
			if (board[i][j] == n) {
				return 0;
			}
		}
	}

	return 1;
}

void dfs(int cnt) {

	if (cnt >= zeroInfo.size()) {
		print();
		exit(0);
	}

	int y = zeroInfo[cnt].y, x = zeroInfo[cnt].x;

	for (int i = 1; i <= 9; i++) {
		if (checkPossibleNumber(i, cnt)) {
			board[y][x] = i;
			dfs(cnt + 1);
			board[y][x] = 0;
		}
	}
}

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			cin >> board[i][j];

			if (!board[i][j]) {
				zeroInfo.push_back({ i,j });
			}
		}
	}

	dfs(0);

	return 0;
}
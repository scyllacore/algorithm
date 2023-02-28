#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct pos {
	int y, x;
};

int dy[] = { -1,1,0,0 };
int dx[] = { 0,0,-1,-1 };

vector<vector<char>> board;
int n, m;


bool move(vector<int>& commands) {

	vector<vector<char>> tmpBoard = board;
	pos r = { 0,0 }, b = { 0,0 };

	int i, j;

	for (i = 0; i < n; i++) {
		for (j = 0; j < m; j++) {
			if (tmpBoard[i][j] == 'R') {
				r.y = i;
				r.x = j;
			}
			else if (tmpBoard[i][j] == 'B') {
				b.y = i;
				b.x = j;
			}
		}
	}

	for (int cmd : commands) {
		if (dy[cmd] != 0) {
			if (dy[cmd] * 10 - r.y > dy[cmd] * 10 - b.y) { // 방향에 따라 누가 더 우선 순위로 옮겨야 하는지 따져줌
				for (i = 1; tmpBoard[r.y + i * dy[cmd]][r.x] == '.'; i++) {}
				if (tmpBoard[r.y + i * dy[cmd]][r.x] == 'O') { return 1; }
				swap(tmpBoard[r.y + (i - 1) * dy[cmd]][r.x], tmpBoard[r.y][r.x]);
				r.y = r.y + (i - 1) * dy[cmd];

				for (i = 1; tmpBoard[b.y + i * dy[cmd]][b.x] == '.'; i++) {}
				if (tmpBoard[b.y + i * dy[cmd]][b.x] == 'O') { return 0; }
				swap(tmpBoard[b.y + (i - 1) * dy[cmd]][b.x], tmpBoard[b.y][b.x]);
				b.y = b.y + (i - 1) * dy[cmd];
			}
			else {
				for (i = 1; tmpBoard[b.y + i * dy[cmd]][b.x] == '.'; i++) {}
				if (tmpBoard[b.y + i * dy[cmd]][b.x] == 'O') { return 0; }
				swap(tmpBoard[b.y + (i - 1) * dy[cmd]][b.x], tmpBoard[b.y][b.x]);
				b.y = b.y + (i - 1) * dy[cmd];


				for (i = 1; tmpBoard[r.y + i * dy[cmd]][r.x] == '.'; i++) {}
				if (tmpBoard[r.y + i * dy[cmd]][r.x] == 'O') { return 1; }
				swap(tmpBoard[r.y + (i - 1) * dy[cmd]][r.x], tmpBoard[r.y][r.x]);
				r.y = r.y + (i - 1) * dy[cmd];
			}
		}
		else {
			if (dy[cmd] * 10 - r.x > dy[cmd] * 10 - b.x) { // 방향에 따라 누가 더 우선 순위로 옮겨야 하는지 따져줌
				for (i = 1; tmpBoard[r.y][r.x + i * dx[cmd]] == '.'; i++) {}
				if (tmpBoard[r.y][r.x + i * dx[cmd]] == 'O') { return 1; }
				swap(tmpBoard[r.y][r.x + (i - 1) * dx[cmd]], tmpBoard[r.y][r.x]);
				r.x = r.x + (i - 1) * dx[cmd];

				for (i = 1; tmpBoard[b.y][b.x + i * dx[cmd]] == '.'; i++) {}
				if (tmpBoard[b.y][b.x + i * dx[cmd]] == 'O') { return 0; }
				swap(tmpBoard[b.y][b.x + (i - 1) * dx[cmd]], tmpBoard[b.y][b.x]);
				b.x = b.x + (i - 1) * dx[cmd];
			}
			else {
				for (i = 1; tmpBoard[b.y][b.x + i * dx[cmd]] == '.'; i++) {}
				if (tmpBoard[b.y][b.x + i * dx[cmd]] == 'O') { return 0; }
				swap(tmpBoard[b.y][b.x + (i - 1) * dx[cmd]], tmpBoard[b.y][b.x]);
				b.x = b.x + (i - 1) * dx[cmd];

				for (i = 1; tmpBoard[r.y][r.x + i * dx[cmd]] == '.'; i++) {}
				if (tmpBoard[r.y][r.x + i * dx[cmd]] == 'O') { return 1; }
				swap(tmpBoard[r.y][r.x + (i - 1) * dx[cmd]], tmpBoard[r.y][r.x]);
				r.x = r.x + (i - 1) * dx[cmd];
			}
		}
	}

	return 0;
}

bool checkAccess(int start, int end, int bitPos) {
	for (int bitCase = start; bitCase < end; bitCase++) {
		vector<int> commands;

		for (int i = 0; i < bitPos; i += 2) {
			int cmd = 0;
			cmd += bitCase & (1 << i) ? 2 : 0;
			cmd += bitCase & (1 << (i + 1)) ? 1 : 0;
			commands.push_back(cmd);
		}

		for (int cmd : commands) {
			cout << cmd << ' ';
		}
		cout << '\n';

		/*if (move(commands)) {
			return 1;
		}*/
	}

	return 0;

}

int main() {

	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> n >> m;
	board.assign(n, vector<char>(m));

	int i, j;

	for (i = 0; i < n; i++) {
		for (j = 0; j < m; j++) {
			cin >> board[i][j];
		}
	}

	int start = 0, end;

	for (int bitPos = 3; bitPos <= 9; bitPos += 2) {
		//cout << i << '\n';    
		//int bitRange = (1 << bitPos); 
		//bitRange <= (1 << bitPos);
		//bitRange = (bitRange << bitPos) for문 조건에 넣었던 것

		end = (1 << bitPos);

		if (checkAccess(start, end, bitPos)) {
			cout << bitPos;
			break;
		}

		start = (1 << bitPos);
	}


	return 0;
}
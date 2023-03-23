#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

#define MAX 10

struct pos {
	int y, x;
};

struct state {
	bool move, success;
};

int dy[] = { 1,-1,0,0 };
int dx[] = { 0,0,1,-1 };

int n, m;

pos r, b;

void getRBOPos(vector<string>& board) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (board[i][j] == 'R') {
				r.y = i, r.x = j;
			}
			else if (board[i][j] == 'B') {
				b.y = i, b.x = j;
			}
		}
	}
}

bool isValid(vector<int>& cmds) {
	int size = cmds.size();

	for (int i = 0; i + 1 < size; i++) {
		if (cmds[i] == 0 && cmds[i + 1] == 1) { return false; }
		if (cmds[i] == 1 && cmds[i + 1] == 0) { return false; }
		if (cmds[i] == 2 && cmds[i + 1] == 3) { return false; }
		if (cmds[i] == 3 && cmds[i + 1] == 2) { return false; }
		if (cmds[i] == cmds[i + 1]) { return false; }
	}

	return true;
}

vector<int> getCommand(int bitCase) {
	vector<int> cmds(MAX);
	for (int i = 0; i < MAX; i++) {
		cmds[i] = (bitCase & 3);
		bitCase >>= 2;
	}
	return cmds;
}

state move(vector<string>& board, int cmd, int& y, int& x) {
	if (board[y][x] == '.') return { false, false };

	bool moved = false;

	for (;;) {
		int ny = y + dy[cmd];
		int nx = x + dx[cmd];

		if (ny < 0 || ny >= n || nx < 0 || nx >= m) {
			return { moved,false };
		}

		if (board[ny][nx] == '#') {
			return { moved, false };
		}
		else if (board[ny][nx] == 'R' || board[ny][nx] == 'B') {
			return { moved, false };
		}
		else if (board[ny][nx] == '.') {
			swap(board[ny][nx], board[y][x]);
			y = ny, x = nx;
			moved = true;
		}
		else if (board[ny][nx] == 'O') {
			board[y][x] = '.';
			return { true, true };
		}

	}
	return { false, false };
}

int getMovingCount(vector<string> board, vector<int>& cmds) {

	int count = 0;

	pos tmpR = r, tmpB = b;

	for (int cmd : cmds) {
		count++;

		bool blueSucess = false, redSucess = false;

		for (;;) {
			state rResult = move(board, cmd, tmpR.y, tmpR.x); // 한 방향으로만 이동하는 함수이어서 이동한 위치를 유지하고 있어야한다.
			state bResult = move(board, cmd, tmpB.y, tmpB.x);
			if (rResult.move == false && bResult.move == false) {
				break;
			}
			if (rResult.success) { redSucess = true; }
			if (bResult.success) { blueSucess = true; }
		}

		if (blueSucess) return -1;
		if (redSucess) return count;
	}
	return -1;
}

int main() {

	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> n >> m;
	vector<string> board(n);

	for (int i = 0; i < n; i++) {
		cin >> board[i];
	}

	getRBOPos(board);

	int answer = -1;

	for (int bitCase = 0; bitCase < (1 << (MAX * 2)); bitCase++) {
		vector<int> cmds = getCommand(bitCase);

		if (!isValid(cmds)) { continue; }

		int result = getMovingCount(board, cmds);
		if (result == -1) { continue; }
		if (answer == -1 || answer > result) { answer = result; }
	}

	cout << answer << '\n';

	return 0;
}

//https://junbastick.tistory.com/37
//https://velog.io/@wlgns2223/%EB%B0%B1%EC%A4%80-13460-%EA%B5%AC%EC%8A%AC-%ED%83%88%EC%B6%9C2
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#define MAX 10
#define NOT_MOVE 11

int dy[] = { -1,1,0,0 };
int dx[] = { 0,0,-1,1 };

struct pos {
	int y, x;
}r, b;

struct state {
	bool move, success;
};

int n, m;

void setBallRB(vector<string>& board) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (board[i][j] == 'R') {
				r.y = i;
				r.x = j;
			}
			if (board[i][j] == 'B') {
				b.y = i;
				b.x = j;
			}
		}
	}
}

vector<int> getCmds(int bitCase) {

	vector<int> cmds;

	for (int i = 0; i < MAX; i++) {
		cmds.push_back(bitCase & 3);
		bitCase = (bitCase >> 2);
	}

	return cmds;
}

bool isNotValid(vector<int>& cmds) {

	for (int i = 0; i < cmds.size() - 1; i++) {
		if (cmds[i] == 0 && cmds[i + 1] == 1) {
			return 1; // 2. return 0;
		}
		if (cmds[i] == 1 && cmds[i + 1] == 0) {
			return 1;
		}
		if (cmds[i] == 2 && cmds[i + 1] == 3) {
			return 1;
		}
		if (cmds[i] == 3 && cmds[i + 1] == 2) {
			return 1;
		}
		if (cmds[i] == cmds[i + 1]) {
			return 1;
		}
	}

	return 0; // 2. return 1;
}

state move(vector<string>& board, int& cmd, int& y, int& x) { // 3(Q). ���⼭ �̹� �� �о��µ�

	if (board[y][x] == '.') {
		return { 0,0 };
	}

	bool moveFlag = 0;

	for (;;) {
		int ny = y + dy[cmd];
		int nx = x + dx[cmd];

		if (ny < 0 || ny >= n || nx < 0 || nx >= m) {
			return { moveFlag,0 };
		}

		if (board[ny][nx] == '#') {
			return { moveFlag,0 };
		}

		if (board[ny][nx] == 'R' || board[ny][nx] == 'B') {
			return { moveFlag,0 };
		}

		if (board[ny][nx] == 'O') {
			board[y][x] = '.'; // 1. board[ny][nx] = '.';
			return { 1,1 };
		}

		if (board[ny][nx] == '.') {
			swap(board[y][x], board[ny][nx]);
			y = ny, x = nx;
			moveFlag = 1;
		}
	}

}

int getMoveCnt(vector<string> board, vector<int>& cmds) {

	pos tmpR = r, tmpB = b;

	for (int cnt = 1; cnt <= MAX; cnt++) {

		int cmd = cmds[cnt - 1];

		bool rSuccess = 0, bSuccess = 0;

		for (;;) { // 3(Q). ���⼭ �� �� for���� ����ұ�?

			/* �ڵ�����δ� ���� ������ ���� ������ �Ķ� ������ ������.
			 ������ RB ������ ���������� ��쿡�� ������ ����.
			 �׷��� BR ������ ���������� ��쿡�� ���� ������ ���� �����µ� �Ķ������� ���� (�������� ����, ���ۿ� ������ ����)
			 �� �����Ѵ�.
			 �׷��� � ������ ���� ������ ������ ���ϴ� ��찡 �߻����� �ʵ��� ���� ������ �̿��Ͽ�
			 ���� �������� ��ȯ�� �ؾ��Ҷ����� ������ �������� �� �ְ� �Ѵ�. */

			 /*�׷��ٸ� �ִ� 2���� �Լ��� ���۽��ѵ� ���� ������?
			 -> Ȯ�� �Ϸ�. 3�� for���� int loop=0; loop<2; loop++�� �־ ���� ���� �Ѵ�.
			 */

			state rState = move(board, cmd, tmpR.y, tmpR.x);
			state bState = move(board, cmd, tmpB.y, tmpB.x);

			if (!rState.move && !bState.move) {
				break;
			}

			if (rState.success) {
				rSuccess = 1;
			}
			if (bState.success) {
				bSuccess = 1;
			}
		}

		if (bSuccess) {
			return NOT_MOVE;
		}
		if (rSuccess) {
			return cnt;
		}
	}

	return NOT_MOVE;
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

	setBallRB(board);

	int answer = NOT_MOVE;

	for (int bitCase = 0; bitCase < (1 << (2 * MAX)); bitCase++) {
		vector<int> cmds = getCmds(bitCase);

		if (isNotValid(cmds)) {
			continue;
		}

		int moveCnt = getMoveCnt(board, cmds);

		answer = min(moveCnt, answer);
	}

	cout << (answer == NOT_MOVE ? -1 : answer);
}

//���� �ڵ庸�� �ӵ��� 4�� ���� ���̳��µ� ������ �𸣰δ�.
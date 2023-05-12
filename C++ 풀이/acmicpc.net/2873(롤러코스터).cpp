#include <iostream>
#include <vector>

using namespace std;

#define SIZE 1000

struct pos {
	int y, x;
}minPos;

int board[SIZE][SIZE] = { {0} };
int r, c;

void move(char dir, int len) {
	for (int i = 0; i < len; i++) {
		cout << dir;
	}
}

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	minPos = { 0,1 };

	cin >> r >> c;
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			cin >> board[i][j];
			if ((i + j) % 2 && board[i][j] < board[minPos.y][minPos.x]) {
				minPos = { i,j };
			}
		}
	}

	if (r % 2) {
		move('R', c - 1);
		for (int i = 1; i <= r - 1; i++) {
			move('D', 1);
			move((i % 2 ? 'L' : 'R'), c - 1);
		}
	}
	else if (c % 2) {
		move('D', r - 1);
		for (int i = 1; i <= c - 1; i++) {
			move('R', 1);
			move((i % 2 ? 'U' : 'D'), r - 1);
		}
	}
	else {
		bool minPosLineFlag = 0;

		for (int i = 0; i < r; i += 2) {
			if (minPos.y == i || minPos.y == i + 1) {
				bool upDownFlag = 0;

				if (i != 0) { // ㄷ의 끝지점에 있는 상황. i가 0인 경우 끝지점이 아닌 시작지점에 위치함으로 내려가면 안됨.
					move('D', 1);
				}

				for (int j = 0; j < c; j++)
				{
					if (j != 0) {
						move('R', 1);
					}
					//j가 0인 상황에서는 상하 이동만 가능함. 1이상인 경우 오른쪽으로 이동후 상하이동을 결정함.
					if (j == minPos.x)
					{
						continue;
					}
					if (upDownFlag) move('U', 1);
					else move('D', 1);
					upDownFlag = !upDownFlag;
				}

				minPosLineFlag = 1;
			}
			else {
				if (i != 0) {
					move('D', 1);
				}

				if (minPosLineFlag) {
					move('L', c - 1);
					move('D', 1);
					move('R', c - 1);
				}
				else {
					move('R', c - 1);
					move('D', 1);
					move('L', c - 1);
				}
			}
		}

	}

	return 0;
}

/*

		int i;

		for (i = 0; i < r; i += 2) {
			if (minPos.y == i || minPos.y == i + 1) {
				break;
			}
			move('R', c - 1);
			move('D', 1);
			move('L', c - 1);
		}

		move('D', 1);
		if (i != 0 && minPos.x != 0) {
			move('D', 1);
		}

		bool upDown = 0;
		for (int j = 0; j < c; j++)
		{
			if (j == minPos.x)
			{
				continue;
			}

			move('R', 1);
			if (upDown) move('U', 1);
			else move('D', 1);
			upDown = !upDown;

		}
		i += 2;

		move('D', 1);
		for (; i < r; i += 2) {
			move('L', c - 1);
			move('D', 1);
			move('R', c - 1);
		}
*/
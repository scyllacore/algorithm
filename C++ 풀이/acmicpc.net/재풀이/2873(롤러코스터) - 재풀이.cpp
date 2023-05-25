#include <iostream>
#include <vector>

using namespace std;

struct pos {
	int y, x;
};

void move(char dir, int len) {
	for (int i = 0; i < len; i++) {
		cout << dir;
	}
}

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	int r, c;
	cin >> r >> c;

	vector<vector<int>> rollerMap(r, vector<int>(c));

	pos minPos = { 0,1 };

	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			cin >> rollerMap[i][j];
			if ((i + j) % 2 && rollerMap[i][j] < rollerMap[minPos.y][minPos.x]) {
				minPos = { i,j };
			}
		}
	}

	if (r % 2) {
		move('R', c - 1);
		for (int i = 1; i < r; i++) {
			move('D', 1);
			move(i % 2 ? 'L' : 'R', c - 1);
		}

		return 0;
	}

	if (c % 2) {
		move('D', r - 1);
		for (int i = 1; i < c; i++) {
			move('R', 1);
			move(i % 2 ? 'U' : 'D', r - 1);
		}
		return 0;
	}

	bool minPosLineFlag = 0;

	for (int i = 0; i < r; i += 2) {
		if (minPos.y == i || minPos.y == i + 1) {

			bool upDownFlag = 0;

			if (i != 0) {
				move('D', 1);
			}

			for (int j = 0; j < c; j++) {
				if (j != 0) {
					move('R', 1);
				}
				if (minPos.x == j) {
					continue;
				}
				move(!upDownFlag ? 'D' : 'U', 1);
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

	return 0;
}
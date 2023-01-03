#include <iostream>
#include <queue>

using namespace std;

int dy[6] = { -2,-2,0,0,2,2 };
int dx[6] = { -1,1,-2,2,-1,1 };

struct pos {
	int y, x;
};

int chess[200][200] = { {0} };
int n;
int r1, c1, r2, c2;

queue<pos> bfsQ;

int BFS() {

	chess[r1][c1] = 1;
	bfsQ.push({ r1,c1 });

	int y, x;
	int nextY, nextX;
	int i;

	while (!bfsQ.empty()) {

		y = bfsQ.front().y;
		x = bfsQ.front().x;
		bfsQ.pop();

		if (y == r2 && x == c2) {
			return chess[y][x] - 1;
		}

		for (i = 0; i < 6; i++) {
			nextY = y + dy[i];
			nextX = x + dx[i];

			if (nextY < 0 || nextY >= n || nextX < 0 || nextX >= n) {
				continue;
			}

			if (!chess[nextY][nextX]) {
				chess[nextY][nextX] = chess[y][x] + 1;
				bfsQ.push({ nextY ,nextX });
			}

		}

	}

	return -1;
}

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> n;

	cin >> r1 >> c1 >> r2 >> c2;

	cout << BFS();

}

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

#define SIZE 100

struct pos {
	int y, x;
};

int dir[] = { -1,1,0,0 };

int n, m;
bool cheeseMap[SIZE][SIZE] = { {0} };
bool visited[SIZE][SIZE];
int touchAir[SIZE][SIZE];

int bfs() {

	int t = 0;

	for (;;) {

		fill(&visited[0][0], &visited[SIZE - 1][SIZE], 0);
		fill(&touchAir[0][0], &touchAir[SIZE - 1][SIZE], 0);

		queue<pos> bfsQ;
		bfsQ.push({ 0,0 });
		visited[0][0] = 1;

		for (; !bfsQ.empty();) {
			pos curP = bfsQ.front();
			bfsQ.pop();

			for (int i = 0; i < 4; i++) {
				int nextY = curP.y + dir[i];
				int nextX = curP.x + dir[3 - i];

				if (nextY < 0 || nextY >= n || nextX < 0 || nextX >= m) {
					continue;
				}

				if (!visited[nextY][nextX] && !cheeseMap[nextY][nextX]) {
					visited[nextY][nextX] = 1;
					bfsQ.push({ nextY,nextX });
				}
				else if (cheeseMap[nextY][nextX]) {
					touchAir[nextY][nextX] += 1;
				}
			}
		}

		int removedCheese = 0;

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (touchAir[i][j] >= 2) {
					cheeseMap[i][j] = 0;
					removedCheese++;
				}
			}
		}

		if (removedCheese == 0) {
			break;
		}

		t++;
	}

	return t;
}

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> cheeseMap[i][j];
		}
	}

	cout << bfs();

	return 0;
}
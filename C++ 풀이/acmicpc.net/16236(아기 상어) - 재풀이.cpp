#include <iostream>
#include <queue>

using namespace std;

#define MAX 20
#define SHARK 9

struct sharkInfo {
	int y, x;
	int move;
};

int dir[] = { -1,1,0,0 };

int n;
int mapNN[MAX][MAX] = { {0} };

struct cmp {
	bool operator()(sharkInfo& s1, sharkInfo& s2) {
		if (s1.move != s2.move) {
			return s1.move > s2.move;
		}

		if (s1.y == s2.y) {
			return s1.x > s2.x;
		}

		return s1.y > s2.y;
	}
};

int bfs(sharkInfo shark) {

	bool visited[MAX][MAX] = { {0} };

	queue<sharkInfo> bfsQ;
	bfsQ.push(shark);
	visited[shark.y][shark.x] = 1;

	int sharkLevel = 2;
	int eatingCount = 0;

	for (;;) {
		priority_queue<sharkInfo, vector<sharkInfo>, cmp> fishQ;

		for (; !bfsQ.empty();) {
			int curY = bfsQ.front().y;
			int curX = bfsQ.front().x;
			int curMove = bfsQ.front().move;
			bfsQ.pop();

			for (int i = 0; i < 4; i++) {
				int nextY = curY + dir[i];
				int nextX = curX + dir[3 - i];
				int nextMove = curMove + 1;

				if (nextY < 0 || nextY >= n || nextX < 0 || nextX >= n) {
					continue;
				}

				if ((!mapNN[nextY][nextX] || mapNN[nextY][nextX] == sharkLevel)
					&& !visited[nextY][nextX]) {
					visited[nextY][nextX] = 1;
					bfsQ.push({ nextY,nextX,nextMove });
				}
				else if (mapNN[nextY][nextX] && mapNN[nextY][nextX] < sharkLevel
					&& !visited[nextY][nextX]) {
					visited[nextY][nextX] = 1;
					fishQ.push({ nextY,nextX,nextMove });
				}
			}
		}

		if (fishQ.empty()) {
			break;
		}

		fill(&visited[0][0], &visited[MAX - 1][MAX], 0);

		shark = fishQ.top();
		bfsQ.push(shark);
		mapNN[shark.y][shark.x] = 0;
		visited[shark.y][shark.x] = 1;

		eatingCount++;

		if (eatingCount == sharkLevel) {
			sharkLevel++;
			eatingCount = 0;
		}
	}

	return shark.move;
}

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> n;

	sharkInfo shark = { 0,0,0 };

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> mapNN[i][j];

			if (mapNN[i][j] == SHARK) {
				shark = { i,j,0 };
				mapNN[i][j] = 0;
			}
		}
	}

	cout << bfs(shark);

	return 0;
}
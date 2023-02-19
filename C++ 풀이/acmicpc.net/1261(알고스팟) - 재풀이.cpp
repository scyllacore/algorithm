#include <cstdio>
#include <deque>

using namespace std;

#define MAX (int)1e2

struct pos {
	int y, x;
};

int dy[] = { -1,1,0,0 };
int dx[] = { 0,0,-1,1 };

bool mapNM[MAX][MAX];
int visited[MAX][MAX] = { {0} };

int n, m;

int bfs() {
	deque<pos> bfsDq;

	visited[0][0] = 1;
	bfsDq.push_back({ 0,0 });

	for (; !bfsDq.empty();) {
		int curY = bfsDq.front().y;
		int curX = bfsDq.front().x;
		bfsDq.pop_front();

		if (curY == m - 1 && curX == n - 1) {
			return visited[curY][curX] - 1;
		}

		for (int i = 0; i < 4; i++) {
			int nextY = curY + dy[i];
			int nextX = curX + dx[i];

			if (nextY < 0 || nextY >= m || nextX < 0 || nextX >= n) {
				continue;
			}

			if (!visited[nextY][nextX]) {
				if (!mapNM[nextY][nextX]) {
					visited[nextY][nextX] = visited[curY][curX];
					bfsDq.push_front({ nextY,nextX });
				}
				else {
					visited[nextY][nextX] = visited[curY][curX] + 1;
					bfsDq.push_back({ nextY,nextX });
				}
			}

		}

	}

	return -1;

}

int main() {

	scanf("%d %d", &n, &m);

	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			scanf("%1d", &mapNM[i][j]);
		}
	}

	printf("%d", bfs());

	return 0;
}
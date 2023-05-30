#include <iostream>
#include <queue>

using namespace std;

#define SIZE 20

struct pos {
	int y, x;
	int move;
};

int dir[] = { -1,1,0,0 };

int n;
int mapNN[SIZE][SIZE];
bool visited[SIZE][SIZE];

struct cmp {
	bool operator()(pos& p1, pos& p2) {
		if (p1.move != p2.move) {
			return p1.move > p2.move;
		}

		if (p1.y == p2.y) {
			return p1.x > p2.x;
		}
		return p1.y > p2.y;
	}
};


int bfs(pos start) {
	queue<pos> bfsQ;

	bfsQ.push(start);
	visited[start.y][start.x] = 1;

	int move = 0;
	int level = 2;
	int eat = 0;

	for (;;) {
		priority_queue<pos, vector<pos>, cmp> pq;

		for (; !bfsQ.empty();) {
			pos curP = bfsQ.front();
			bfsQ.pop();

			for (int i = 0; i < 4; i++) {
				int nextY = curP.y + dir[i];
				int nextX = curP.x + dir[3 - i];

				if (nextY < 0 || nextY >= n || nextX < 0 || nextX >= n) {
					continue;
				}

				if (!visited[nextY][nextX]) {
					visited[nextY][nextX] = 1;

					if (mapNN[nextY][nextX] <= level) {
						bfsQ.push({ nextY,nextX,curP.move + 1 });
					}
					if (mapNN[nextY][nextX] > 0 && mapNN[nextY][nextX] < level) {
						pq.push({ nextY,nextX,curP.move + 1 });
					}
				}
			}
		}


		fill(&visited[0][0], &visited[SIZE - 1][SIZE], 0);

		if (pq.empty()) {
			break;
		}

		move += pq.top().move;
		eat++;

		bfsQ.push({ pq.top().y, pq.top().x,0 });
		mapNN[pq.top().y][pq.top().x] = 0;
		visited[pq.top().y][pq.top().x] = 1; // »©¸ÔÀ½.

		if (eat == level) {
			level++;
			eat = 0;
		}
	}

	return move;
}

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> n;

	pos start = { 0,0,0 };

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> mapNN[i][j];
			if (mapNN[i][j] == 9) {
				start = { i,j,0 };
				mapNN[i][j] = 0;
			}
		}
	}

	cout << bfs(start);

	return 0;
}
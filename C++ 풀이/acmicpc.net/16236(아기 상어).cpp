#include <iostream>
#include <vector>
#include <queue>

#define MAX_IDX 20
#define MAX_DIST 400

using namespace std;

int n;
int mapNN[21][21];
bool visited[21][21];

int dy[4] = { -1,0,1,0 };
int dx[4] = { 0,-1,0,1 };

struct pos {
	int y, x, t;
};

struct cmp {
	bool operator()(const pos& p1, const pos& p2) {

		if (p1.t == p2.t) {
			if (p1.y == p2.y) {
				return p1.x > p2.x;
			}
			else {
				return p1.y > p2.y;
			}
		}
		else {
			return p1.t > p2.t;
		}

	}
};


int BFS(int y, int x) {

	queue<pos> bfsQ;
	bfsQ.push({ y,x ,0 });
	visited[y][x] = 1;

	int moveCnt = 0, eat = 0, sharkLev = 2;

	int i;
	int curY, curX, curT;
	int nextY, nextX;

	while (1) {

		priority_queue<pos, vector<pos>, cmp> pQ;

		while (!bfsQ.empty()) {
			curY = bfsQ.front().y;
			curX = bfsQ.front().x;
			curT = bfsQ.front().t;
			bfsQ.pop();

			for (i = 0; i < 4; i++) {
				nextY = curY + dy[i];
				nextX = curX + dx[i];

				if (nextY < 1 || nextY > n || nextX < 1 || nextX > n) { continue; }
				if (mapNN[nextY][nextX] > sharkLev || visited[nextY][nextX]) { continue; }

				bfsQ.push({ nextY,nextX,curT + 1 });
				visited[nextY][nextX] = 1;

				if (mapNN[nextY][nextX] < sharkLev && mapNN[nextY][nextX] >0) {
					pQ.push({ nextY,nextX, curT + 1 });
				}


			}
		}

		fill(&visited[0][0], &visited[20][21], 0);

		if (!pQ.empty()) {
			int pqY = pQ.top().y;
			int pqX = pQ.top().x;
			int pqT = pQ.top().t;
			pQ.pop();

			mapNN[pqY][pqX] = 0;

			if ((++eat) == sharkLev) {
				sharkLev++;
				eat = 0;
			}
			moveCnt = pqT;

			bfsQ.push({ pqY,pqX,pqT });
			visited[pqY][pqX] = 1;
		}
		else {
			return moveCnt;
		}

	}

}

int main() {

	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> n;

	int i, j;
	int y = 1, x = 1;

	for (i = 1; i <= n; i++) {
		for (j = 1; j <= n; j++) {
			cin >> mapNN[i][j];

			if (mapNN[i][j] == 9) {
				y = i, x = j;
				mapNN[y][x] = 0;
			}

		}
	}

	cout << BFS(y, x);



	return 0;

}



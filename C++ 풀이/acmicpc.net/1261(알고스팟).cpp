#include <cstdio>
#include <deque>
#include <algorithm>


using namespace std;

bool map[101][101] = { {0} };
bool visited[101][101] = { {0} };

int n, m;
int dy[4] = { -1,1,0,0 };
int dx[4] = { 0,0,-1,1 };

typedef struct Operator {
	int y, x;
	int wall;
};

int ans = 99999;

deque<Operator> spotBFS;

int BFS() {

	int ySpot, xSpot, wallN;
	int i;
	int yNext, xNext;

	while (!spotBFS.empty()) {

		ySpot = spotBFS.front().y;
		xSpot = spotBFS.front().x;
		wallN = spotBFS.front().wall;
		spotBFS.pop_front();

		if (ySpot == m && xSpot == n) {
			return wallN;
		}

		for (i = 0; i < 4; i++) {
			yNext = ySpot + dy[i];
			xNext = xSpot + dx[i];

			if (yNext >= 1 && yNext <= m && xNext >= 1 && xNext <= n) {
				if (!visited[yNext][xNext]) {
					if (map[yNext][xNext]) {
						spotBFS.push_back({ yNext,xNext,wallN + 1 });
					}
					else {
						spotBFS.push_front({ yNext,xNext,wallN });
					}
					visited[yNext][xNext] = 1;
				}

			}


		}


	}

}

int main() {

	scanf("%d %d", &n, &m);

	int i, j;

	for (i = 1; i <= m; i++) {
		for (j = 1; j <= n; j++) {
			scanf("%1d", &map[i][j]);
		}
	}

	visited[1][1] = 1;
	spotBFS.push_back({ 1, 1, 0 });


	printf("%d", BFS());

	return 0;

}
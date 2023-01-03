#include <cstdio>
#include <queue>

using namespace std;

int nOmove[101][101] = { {0},{0,1} }; // num of move

int dy[4] = { -1,1,0,0 };
int dx[4] = { 0,0,-1,1 };

queue<pair<int, int>> nodeBFS;
int n, m;

void BFS(int y, int x) {

	int i, nextX, nextY;

	while (!nodeBFS.empty()) {
		y = nodeBFS.front().first;
		x = nodeBFS.front().second;

		for (i = 0; i < 4; i++) {

			nextY = y + dy[i];
			nextX = x + dx[i];

			if (nextY >= 1 && nextY <= n && nextX >= 1 && nextX <= m) {
				if (nOmove[nextY][nextX] == 1) {
					nOmove[nextY][nextX] = nOmove[y][x] + 1;
					nodeBFS.push(make_pair(nextY, nextX));
				}

			}
		}

		nodeBFS.pop();

	}

}


int main() {

	scanf("%d %d", &n, &m);

	int i, j;

	for (i = 1; i <= n; i++) {
		for (j = 1; j <= m; j++) {
			scanf("%1d", &nOmove[i][j]);
		}
	}

	nodeBFS.push(make_pair(1, 1));
	BFS(1, 1);

	printf("%d", nOmove[n][m]);

	return 0;
}


/*
방문체크를 37번재줄에서 하시면 안되고, 넣으면서(31번줄에서) 하셔야 합니다.

예를들어보죠.

1 2 3
4 5 6
7 8 9

모두 데이터상으론 1인데 설명 편의를 위해 숫자를 붙였습니다.

1을 큐에 넣고 0으로 바꿈.
2랑 4를 큐에 넣음.
2를 poll하고 2를 0으로 바꾸고 3과 5를 넣음.
4를 poll하고 4를 0으로 바꾸고 5와 7을 넣음.
3을 poll하고 0으로 바꾸고 6을 넣음.
0 0 0
0 5 6
7 8 9

현재 상태입니다.

6. 5를 poll하고 0으로 바꾸고 6과 8을 넣음

7. 5를 poll하고 0이지만 또 0으로 바꾸고 6과 8을 넣음

8. ... (2의 제곱수로 push하게 된다.)

보시다시피 중복으로 들어가는게 생기게 되면 계속 불어나게됩니다.
*/
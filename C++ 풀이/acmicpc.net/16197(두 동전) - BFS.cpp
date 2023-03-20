#include <iostream>
#include <queue>

#define MAX 21
using namespace std;

int n, m;
char board[21][21] = { {0} };
int dy[4] = { -1,1,0,0 };
int dx[4] = { 0,0,-1,1 };


struct coin {
	int y1, x1;
	int y2, x2;
	int cnt;
};

bool visited[MAX][MAX][MAX][MAX];
coin posCoin;
queue<coin> coinQ;

bool isOut(int y, int x) {
	return y < 1 || y > n || x < 1 || x > m;
}


int BFS() {

	int i, j;
	int nextY1, nextX1, nextY2, nextX2;
	coin tmpCoin;

	coinQ.push({ posCoin.y1,posCoin.x1,posCoin.y2,posCoin.x2,0 });

	while (!coinQ.empty()) {
		tmpCoin = coinQ.front();
		coinQ.pop();

		if (tmpCoin.cnt > 10) {
			break;
		}

		for (i = 0; i < 4; i++) {
			nextY1 = tmpCoin.y1 + dy[i];
			nextX1 = tmpCoin.x1 + dx[i];
			nextY2 = tmpCoin.y2 + dy[i];
			nextX2 = tmpCoin.x2 + dx[i];

			if (isOut(nextY1, nextX1) && isOut(nextY2, nextX2)) {
				continue;
			}

			if (board[nextY1][nextX1] == '#') {
				nextY1 = tmpCoin.y1;
				nextX1 = tmpCoin.x1;
			}
			if (board[nextY2][nextX2] == '#') {
				nextY2 = tmpCoin.y2;
				nextX2 = tmpCoin.x2;
			}

			if ((!isOut(nextY1, nextX1) && isOut(nextY2, nextX2)) 
				|| (isOut(nextY1, nextX1) && !isOut(nextY2, nextX2))) {
				if (tmpCoin.cnt + 1 <= 10) { return tmpCoin.cnt + 1; }
				else { return -1; }
			}

			if (!visited[nextY1][nextX1][nextY2][nextX2]) {
				visited[nextY1][nextX1][nextY2][nextX2] = 1;
				coinQ.push({ nextY1,nextX1,nextY2,nextX2 ,tmpCoin.cnt + 1 });
			}
		}

	}

	return -1;

}

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> n >> m;

	int i, j, num = 0;
	char ch;

	for (i = 1; i <= n; i++) {
		for (j = 1; j <= m; j++) {
			cin >> ch;
			board[i][j] = ch;
			if (ch == 'o') {
				if (num == 0) {
					posCoin.y1 = i;
					posCoin.x1 = j;
					num++;
				}
				else {
					posCoin.y2 = i;
					posCoin.x2 = j;
				}
			}
		}
	}

	cout << BFS();

	return 0;

}

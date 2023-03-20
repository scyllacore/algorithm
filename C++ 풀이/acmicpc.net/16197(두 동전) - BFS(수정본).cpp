#include <iostream>
#include <queue>
#include <vector>

#define MAX 21

using namespace std;

int n, m;
char board[22][22] = { {0} };

int dy[4] = { -1,1,0,0 };
int dx[4] = { 0,0,-1,1 };


struct coinPos {
	int y, x;
};

struct twoCoinInfo {
	coinPos coin1, coin2;
	int cnt;
};

bool visited[MAX][MAX][MAX][MAX];

bool isOut(coinPos coin) {
	return coin.y < 1 || coin.y > n || coin.x < 1 || coin.x > m;
}

int BFS(vector<coinPos>& twoCoin) {

	queue<twoCoinInfo> coinQ;

	coinQ.push({ {twoCoin[0].y,twoCoin[0].x }, {twoCoin[1].y,twoCoin[1].x }, 0 });

	while (!coinQ.empty()) {
		twoCoinInfo curInfo = coinQ.front();
		coinQ.pop();

		if (curInfo.cnt > 10) {
			break;
		}

		if (isOut(curInfo.coin1) && isOut(curInfo.coin2)) {
			continue;
		}

		if ((!isOut(curInfo.coin1) && isOut(curInfo.coin2))
			|| (isOut(curInfo.coin1) && !isOut(curInfo.coin2))) {
			return curInfo.cnt;
		}

		for (int i = 0; i < 4; i++) {
			coinPos nextCoin1 = { curInfo.coin1.y + dy[i] , curInfo.coin1.x + dx[i] };
			coinPos nextCoin2 = { curInfo.coin2.y + dy[i] , curInfo.coin2.x + dx[i] };

			if (board[nextCoin1.y][nextCoin1.x] == '#') {
				nextCoin1 = curInfo.coin1;
			}

			if (board[nextCoin2.y][nextCoin2.x] == '#') {
				nextCoin2 = curInfo.coin2;
			}

			if (!visited[nextCoin1.y][nextCoin1.x][nextCoin2.y][nextCoin2.x]) {
				visited[nextCoin1.y][nextCoin1.x][nextCoin2.y][nextCoin2.x] = 1;
				coinQ.push({ {nextCoin1.y,nextCoin1.x},{nextCoin2.y,nextCoin2.x} ,curInfo.cnt + 1 });
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
	vector<coinPos> posCoin;

	for (i = 1; i <= n; i++) {
		for (j = 1; j <= m; j++) {
			cin >> board[i][j];
			if (board[i][j] == 'o') {
				posCoin.push_back({ i,j });
			}
		}
	}

	cout << BFS(posCoin);

	return 0;

}

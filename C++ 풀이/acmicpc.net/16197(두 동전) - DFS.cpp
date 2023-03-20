#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct coinInfo {
	int y, x;
};

int dy[] = { -1,1,0,0 };
int dx[] = { 0,0,-1,1 };

char board[22][22] = { NULL };
//** char board[20][20] = { NULL }; board[nextCoin1.y][nextCoin1.x]를 접근할 때 배열 구간이 아닌 곳을 접근할 수 있음으로 문제가 될 수 있다.
int n, m;

int minMovingCnt = 11;

bool isOut(coinInfo& coin) {
	return coin.y < 1 || coin.y > n || coin.x < 1 || coin.x > m;
	//** return coin.y < 0 || coin.y >= n || coin.x < 0 || coin.x >= m; 이에 따라 배열에 여유를 주고 범위를 수정하였음.
}

void dfs(coinInfo& coin1, coinInfo& coin2, int movingCnt) {
	if (movingCnt > 10) {
		return;
	}

	if (isOut(coin1) && isOut(coin2)) {
		return;
	}

	if ((isOut(coin1) && !isOut(coin2))
		|| (!isOut(coin1) && isOut(coin2))) {
		minMovingCnt = min(movingCnt, minMovingCnt);
		return;
	}

	for (int i = 0; i < 4; i++) {
		coinInfo nextCoin1 = { coin1.y + dy[i], coin1.x + dx[i] };
		coinInfo nextCoin2 = { coin2.y + dy[i], coin2.x + dx[i] };

		if (board[nextCoin1.y][nextCoin1.x] == '#') { // != '.' 
			nextCoin1 = coin1;
		}
		if (board[nextCoin2.y][nextCoin2.x] == '#') {
			nextCoin2 = coin2;
		}
		// 동전이 겹치는 경우에 대해서는 따로 신경쓰지 않은 듯 싶다. 겹치는 경우가 존재한다.

		dfs(nextCoin1, nextCoin2, movingCnt + 1);
	}

}

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> n >> m;

	vector<coinInfo> coin;

	int i, j;
	for (i = 1; i <= n; i++) {
		for (j = 1; j <= m; j++) {
			cin >> board[i][j];
			if (board[i][j] == 'o') {
				coin.push_back({ i,j });
			}

		}
	}

	dfs(coin[0], coin[1], 0);

	cout << (minMovingCnt == 11 ? -1 : minMovingCnt);

	return 0;
}
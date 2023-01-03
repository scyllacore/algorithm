#include <iostream>
#include <queue>

using namespace std;

int mapL[300][300] = { {0} };
int l;
int desY, desX;
int startY, startX;

struct Pos {
	int y, x;
};

int dy[8] = { -2,-1,1,2,2,1,-1,-2 };
int dx[8] = { 1,2,2,1,-1,-2,-2,-1 };


int BFS() {

	queue<Pos> bfsQ;


	mapL[startY][startX] = 1;
	bfsQ.push({ startY,startX });

	int i;
	int curY, curX;
	int nextY, nextX;

	while (!bfsQ.empty()) {

		curY = bfsQ.front().y;
		curX = bfsQ.front().x;
		bfsQ.pop();


		if (curY == desY && curX == desX) {
			return mapL[curY][curX]-1;
		}

		for (i = 0; i < 8; i++) {
			nextY = curY + dy[i];
			nextX = curX + dx[i];

			if (nextY >= 0 && nextY < l && nextX >= 0 && nextX < l) {
				if (!mapL[nextY][nextX]) {
					mapL[nextY][nextX] = mapL[curY][curX] + 1;
					bfsQ.push({nextY,nextX});
				}
			}

		}
	}


}

int main() {

	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	int tc;
	cin >> tc;

	int i, j;

	while ((tc--) > 0) {

		cin >> l;
		cin >> startX >> startY;
		cin >> desX >> desY;

		cout << BFS() << '\n';

		fill(&mapL[0][0], &mapL[l - 1][l], 0);

	}

	return 0;

}

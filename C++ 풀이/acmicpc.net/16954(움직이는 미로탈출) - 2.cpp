#include <iostream>
#include <queue>

using namespace std;

string chess[8];
int visited[8][8] = { {0} };

struct pos {
	int y, x, t;
};

int dy[9] = { 0,-1 ,-1, -1,0,0,1,1,1 };
int dx[9] = { 0,-1,0,1,-1,1,-1,0,1 };


void moveDown() {

	int i;

	string tmp = "........";

	for (i = 7; i > 0; i--) {
		chess[i] = chess[i-1];
	}
	chess[0] = tmp;
}

bool bfs() {

	queue<pos> bfsQ;
	bfsQ.push({ 7,0,1 });
	visited[7][0] = 1;

	int timeCheck = 1;

	int curY, curX, curT;
	int nextY, nextX;
	int i;

	while (!bfsQ.empty()) {
		curY = bfsQ.front().y;
		curX = bfsQ.front().x;
		curT = bfsQ.front().t;
		bfsQ.pop();

		if (curY == 0 && curX == 7) {
			return 1;
		}

		if (curT != timeCheck) {
			moveDown();
			timeCheck = curT;
		}

		if (chess[curY][curX] == '#') continue;

		for (i = 0; i < 9; i++) {
			nextY = curY + dy[i];
			nextX = curX + dx[i];

			if (nextY < 0 || nextY > 7 || nextX < 0 || nextX > 7 || visited[nextY][nextX] == curT + 1) {
				continue;
			}

			if (chess[nextY][nextX] == '.') {
				bfsQ.push({ nextY,nextX,curT + 1 });
				visited[nextY][nextX] = curT + 1;
			}

		}
	}

	return 0;
}

int main() {

	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	int i;


	for (i = 0; i < 8; i++) {
		cin >> chess[i];
	}

	//for (i = 0; i < 8; i++) {
	//	moveDown();

	//	for (int j = 0; j < 8; j++) {
	//		cout <<  chess[j] << '\n';
	//	}

	//	cout << '\n';

	//}

	cout << bfs();

	return 0;

}


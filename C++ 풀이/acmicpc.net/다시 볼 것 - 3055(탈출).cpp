#include <iostream>
#include <queue>
#include <vector>
#include <string>

using namespace std;

#define MAX 50

struct spotInfo {
	int y, x;
	int t;
};

int dir[] = { -1,1,0,0 };

int r, c;
char forestMap[MAX][MAX];

bool visited[MAX][MAX] = { {0} };

queue<spotInfo> water;

void spread() {
	int curTime = water.front().t;

	// 실수 2.  curTime != curT. 
	// 2-1. 조건을 여기다 넣으면 안됨 
	// 2-2. waterQ가 없다면 더 이상 진행할 수 없음.
	for (; !water.empty();) {
		int curY = water.front().y;
		int curX = water.front().x;
		int curT = water.front().t;

		if (curTime != curT) {
			break;
		}

		water.pop(); //실수3. curTime != curT를 확인하고 빼야됨.

		for (int i = 0; i < 4; i++) {
			int nextY = curY + dir[i];
			int nextX = curX + dir[3 - i];
			int nextT = curT + 1;

			if (nextY < 0 || nextY >= r || nextX < 0 || nextX >= c) { // 실수1. nextY >= c
				continue;
			}

			if (forestMap[nextY][nextX] == '.') {
				forestMap[nextY][nextX] = '*';
				water.push({ nextY,nextX,nextT });
			}
		}
	}

}

string bfs(spotInfo& s, spotInfo& w) {

	queue<spotInfo> bfsQ;
	bfsQ.push({ s.y,s.x,1 });
	visited[s.y][s.x] = 1;

	int curTime = 1;

	for (; !bfsQ.empty();) {
		int curY = bfsQ.front().y;
		int curX = bfsQ.front().x;
		int curT = bfsQ.front().t;
		bfsQ.pop();

		if (curTime != curT) { //분석할 것 1. pop과 spread 순서. -> 상관 없음.
			spread();
			curTime = curT;
		}


		if (forestMap[curY][curX] == 'D') {
			return to_string(curT - 1);
		}

		if (forestMap[curY][curX] != '.') { //실수 4. forestMap[curY][curX] == '*'
			continue;
		}

		for (int i = 0; i < 4; i++) {
			int nextY = curY + dir[i];
			int nextX = curX + dir[3 - i];
			int nextT = curT + 1;

			if (nextY < 0 || nextY >= r || nextX < 0 || nextX >= c) {
				continue;
			}

			if (forestMap[nextY][nextX] != '*' && !visited[nextY][nextX]) { //실수5. forestMap[nextY][nextX] == '.' 
				visited[nextY][nextX] = 1;
				bfsQ.push({ nextY,nextX,nextT });
			}
		}
	}

	return "KAKTUS";

}

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> r >> c;

	spotInfo s, w;

	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			cin >> forestMap[i][j];
			if (forestMap[i][j] == 'S') {
				s.y = i;
				s.x = j;
				forestMap[i][j] = '.';
			}
			if (forestMap[i][j] == '*') {
				water.push({ i,j,1 });
			}
		}
	}

	cout << bfs(s, w);
	return 0;
}
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

int visited[MAX][MAX] = { {0} };

queue<spotInfo> water;

void spread() {
	int curTime = water.front().t;
	int curT = water.front().t;

	for (; curTime != curT;) {
		int curY = water.front().y;
		int curX = water.front().x;
		curT = water.front().t;
		water.pop();


		for (int i = 0; i < 4; i++) {
			int nextY = curY + dir[i];
			int nextX = curX + dir[3 - i];
			int nextT = curT + 1;

			if (nextY < 0 || nextY >= r || nextX < 0 || nextY >= c) {
				continue;
			}

			if (forestMap[nextY][nextX] == '.') {
				forestMap[nextY][nextX] = '*';
				water.push({ nextY,nextX,nextT });
			}
		}

	}

	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			cout << forestMap[i][j];
		}
		cout << '\n';
	}

	cout << '\n';

}

string bfs(spotInfo& s, spotInfo& w) {

	queue<spotInfo> bfsQ;
	bfsQ.push({ s.y,s.x,1 });
	visited[s.y][s.x] = 1;

	water.push({ w.y,w.x,1 });

	int curTime = 1;

	for (; !bfsQ.empty();) {
		int curY = bfsQ.front().y;
		int curX = bfsQ.front().x;
		int curT = bfsQ.front().t;
		bfsQ.pop();

		if (forestMap[curY][curX] == 'D') {
			return to_string(curT - 1);
		}

		if (curTime != curT) {
			spread();
			curTime = curT;
		}

		if (forestMap[curY][curX] == '*') {
			continue;
		}

		for (int i = 0; i < 4; i++) {
			int nextY = curY + dir[i];
			int nextX = curX + dir[3 - i];
			int nextT = curT + 1;

			if (nextY < 0 || nextY >= r || nextX < 0 || nextY >= c) {
				continue;
			}

			if (visited[nextY][nextX] == nextT) {
				continue;
			}

			if (forestMap[nextY][nextX] == '.') {
				visited[nextY][nextX] = nextT;
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
				w.y = i;
				w.x = j;
			}
		}
	}

	cout << bfs(s, w);
}



2.


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

int visited[MAX][MAX] = { {0} };

queue<spotInfo> water;

void spread() {
	int curTime = water.front().t;

	for (;;) { // 실수 2.  curTime != curT. 2-1. 조건을 여기다 넣으면 안됨
		int curY = water.front().y;
		int curX = water.front().x;
		int curT = water.front().t;

		if (curTime != curT) {
			break;
		}

		water.pop(); //실수3. 확인하고 빼야됨.

		for (int i = 0; i < 4; i++) {
			int nextY = curY + dir[i];
			int nextX = curX + dir[3 - i];
			int nextT = curT + 1;

			if (nextY < 0 || nextY >= r || nextX < 0 || nextX >= c) { // 실수1. nextY >= c
				continue;
			}

			if (forestMap[nextY][nextX] == '.') {
				forestMap[nextY][nextX] = '*';
				cout << nextY << ' ' << nextX << ' ' << nextT << '\n';
				water.push({ nextY,nextX,nextT });
			}
		}

	}

	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			cout << forestMap[i][j];
		}
		cout << '\n';
	}

	cout << '\n';

}

string bfs(spotInfo& s, spotInfo& w) {

	queue<spotInfo> bfsQ;
	bfsQ.push({ s.y,s.x,1 });
	visited[s.y][s.x] = 1;

	water.push({ w.y,w.x,1 });

	int curTime = 1;

	for (; !bfsQ.empty();) {
		int curY = bfsQ.front().y;
		int curX = bfsQ.front().x;
		int curT = bfsQ.front().t;
		bfsQ.pop();

		if (forestMap[curY][curX] == 'D') {
			return to_string(curT - 1);
		}

		if (curTime != curT) {
			spread();
			curTime = curT;
		}

		if (forestMap[curY][curX] == '*') {
			continue;
		}

		for (int i = 0; i < 4; i++) {
			int nextY = curY + dir[i];
			int nextX = curX + dir[3 - i];
			int nextT = curT + 1;

			if (nextY < 0 || nextY >= r || nextX < 0 || nextX >= c) {
				continue;
			}

			if (visited[nextY][nextX] == nextT) {
				continue;
			}

			if (forestMap[nextY][nextX] == '.') {
				visited[nextY][nextX] = nextT;
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

	//cout << bfs(s, w);
	spread();
	spread();

}

3.
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

	for (;;) { // 실수 2.  curTime != curT. 2-1. 조건을 여기다 넣으면 안됨
		int curY = water.front().y;
		int curX = water.front().x;
		int curT = water.front().t;

		if (curTime != curT) {
			break;
		}

		water.pop(); //실수3. 확인하고 빼야됨.

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
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			cout << forestMap[i][j];
		}
		cout << '\n';
	}

	cout << '\n';

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

		cout << curY << ' ' << curX << ' ' << curT << '\n';

		if (curTime != curT) {
			spread();
			curTime = curT;
		}

		bfsQ.pop();

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
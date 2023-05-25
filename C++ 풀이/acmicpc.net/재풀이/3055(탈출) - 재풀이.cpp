#include <iostream>
#include <queue>
#include <string>

using namespace std;

#define MAX 50
#define MAX_MOVE 2501

struct spotInfo {
	int y, x;
};

int dir[] = { -1,1,0,0 };

int waterTime[MAX][MAX];
int visited[MAX][MAX] = { {0} };

int r, c;

void fillWater(vector<string>& forestMap) {
	queue<spotInfo> bfsQ;

	fill(&waterTime[0][0], &waterTime[MAX - 1][MAX], MAX_MOVE); // 오류1. 물을 채울 수 없는 지점은 최댓값으로 처리해야한다.

	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			if (forestMap[i][j] == '*') {
				bfsQ.push({ i,j });
				waterTime[i][j] = 1;
			}
		}
	}

	for (; !bfsQ.empty();) {
		int curY = bfsQ.front().y;
		int curX = bfsQ.front().x;
		bfsQ.pop();

		for (int i = 0; i < 4; i++) {
			int nextY = curY + dir[i];
			int nextX = curX + dir[3 - i];
			int nextT = waterTime[curY][curX] + 1;

			if (nextY < 0 || nextY >= r || nextX < 0 || nextX >= c) {
				continue;
			}

			if (forestMap[nextY][nextX] == '.' && waterTime[nextY][nextX] == MAX_MOVE) {
				waterTime[nextY][nextX] = nextT;
				bfsQ.push({ nextY,nextX });
			}
		}
	}
}

string bfs(vector<string>& forestMap, spotInfo& start) {
	queue<spotInfo> bfsQ;
	bfsQ.push(start);
	visited[start.y][start.x] = 1;

	for (; !bfsQ.empty();) {
		int curY = bfsQ.front().y;
		int curX = bfsQ.front().x;
		bfsQ.pop();

		if (forestMap[curY][curX] == 'D') {
			return to_string(visited[curY][curX] - 1);
		}

		for (int i = 0; i < 4; i++) {
			int nextY = curY + dir[i];
			int nextX = curX + dir[3 - i];
			int nextT = visited[curY][curX] + 1;

			if (nextY < 0 || nextY >= r || nextX < 0 || nextX >= c) {
				continue;
			}

			if (forestMap[nextY][nextX] != '.' && forestMap[nextY][nextX] != 'D') { // 다음 지점이 벽이나 물 지점이라면 건너뜀 
				continue;
			}

			if (!visited[nextY][nextX] && nextT < waterTime[nextY][nextX]) { // 현재 물이 안 차있어서 접근이 가능한지 확인.
				visited[nextY][nextX] = nextT;
				bfsQ.push({ nextY,nextX });
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

	vector<string> forestMap(r);

	for (int i = 0; i < r; i++) {
		cin >> forestMap[i];
	}

	spotInfo start = { 0,0 }, end = { 0,0 };

	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			if (forestMap[i][j] == 'S') {
				start.y = i;
				start.x = j;
				break;
			}
		}
	}

	fillWater(forestMap);
	cout << bfs(forestMap, start);

	return 0;
}

//5 5
//* .XS.
//..X..
//..X..
//..X..
//..X.D

/*
#include <iostream>
#include <queue>
#include <string>

using namespace std;

#define MAX 50

struct spotInfo {
	int y, x;
};

int dir[] = { -1,1,0,0 };

int waterTime[MAX][MAX];
int visited[MAX][MAX];

int r, c;

void fillWater(vector<string>& forestMap) {
	queue<spotInfo> bfsQ;

	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			if (forestMap[i][j] == '*') {
				bfsQ.push({ i,j });
				waterTime[i][j] = 1;
			}
		}
	}

	for (; !bfsQ.empty();) {
		int curY = bfsQ.front().y;
		int curX = bfsQ.front().x;
		bfsQ.pop();

		for (int i = 0; i < 4; i++) {
			int nextY = curY + dir[i];
			int nextX = curX + dir[3 - i];
			int nextT = waterTime[curY][curX] + 1;

			if (nextY < 0 || nextY >= r || nextX < 0 || nextX >= c) {
				continue;
			}

			if (forestMap[nextY][nextX] == '.' && !waterTime[nextY][nextX]) {
				waterTime[nextY][nextX] = nextT;
				bfsQ.push({ nextY,nextX });
			}

		}
	}

	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			cout << waterTime[i][j] << ' ';
		}
		cout << '\n';
	}

	cout << '\n';
}

string bfs(vector<string>& forestMap, spotInfo& start) {
	queue<spotInfo> bfsQ;
	bfsQ.push(start);
	visited[start.y][start.x] = 1;

	for (; !bfsQ.empty();) {
		int curY = bfsQ.front().y;
		int curX = bfsQ.front().x;
		bfsQ.pop();

		if (forestMap[curY][curX] == 'D') {
			return to_string(visited[curY][curX] - 1);
		}

		for (int i = 0; i < 4; i++) {
			int nextY = curY + dir[i];
			int nextX = curX + dir[3 - i];
			int nextT = visited[curY][curX] + 1;

			if (nextY < 0 || nextY >= r || nextX < 0 || nextX >= c) {
				continue;
			}

			if ((forestMap[nextY][nextX] == '.' || forestMap[nextY][nextX] == 'D')
				&& !visited[nextY][nextX] && nextT < waterTime[nextY][nextX]) {
				visited[nextY][nextX] = nextT;
				bfsQ.push({ nextY,nextX });
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

	vector<string> forestMap(r);

	string line;
	for (int i = 0; i < r; i++) {
		cin >> forestMap[i];
	}

	spotInfo start = { 0,0 }, end = { 0,0 };

	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			if (forestMap[i][j] == 'S') {
				start.y = i;
				start.x = j;
				forestMap[i][j] = '.';
			}
			else if (forestMap[i][j] == 'D') {
				end.y = i;
				end.x = j;
			}
		}
	}

	waterTime[end.y][end.x] = 9;

	fillWater(forestMap);
	cout << bfs(forestMap, start) << "\n\n";

	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			cout << visited[i][j] << ' ';
		}
		cout << '\n';
	}

	cout << '\n';

}


//

#include <iostream>
#include <queue>
#include <string>

using namespace std;

#define MAX 50

struct spotInfo {
	int y, x;
};

int dir[] = { -1,1,0,0 };

int waterTime[MAX][MAX];
int visited[MAX][MAX];

int r, c;

void fillWater(vector<string>& forestMap) {
	queue<spotInfo> bfsQ;

	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			if (forestMap[i][j] == '*') {
				bfsQ.push({ i,j });
				waterTime[i][j] = 1;
			}
		}
	}

	for (; !bfsQ.empty();) {
		int curY = bfsQ.front().y;
		int curX = bfsQ.front().x;
		bfsQ.pop();

		for (int i = 0; i < 4; i++) {
			int nextY = curY + dir[i];
			int nextX = curX + dir[3 - i];
			int nextT = waterTime[curY][curX] + 1;

			if (nextY < 0 || nextY >= r || nextX < 0 || nextX >= c) {
				continue;
			}

			if (forestMap[nextY][nextX] == '.' && !waterTime[nextY][nextX]) {
				waterTime[nextY][nextX] = nextT;
				bfsQ.push({ nextY,nextX });
			}
		}
	}
}

string bfs(vector<string>& forestMap, spotInfo& start) {
	queue<spotInfo> bfsQ;
	bfsQ.push(start);
	visited[start.y][start.x] = 1;

	for (; !bfsQ.empty();) {
		int curY = bfsQ.front().y;
		int curX = bfsQ.front().x;
		bfsQ.pop();

		if (forestMap[curY][curX] == 'D') {
			return to_string(visited[curY][curX] - 1);
		}

		for (int i = 0; i < 4; i++) {
			int nextY = curY + dir[i];
			int nextX = curX + dir[3 - i];
			int nextT = visited[curY][curX] + 1;

			if (nextY < 0 || nextY >= r || nextX < 0 || nextX >= c) {
				continue;
			}

			if ((forestMap[nextY][nextX] == '.' || forestMap[nextY][nextX] == 'D')
				&& !visited[nextY][nextX] && nextT < waterTime[nextY][nextX]) {
				visited[nextY][nextX] = nextT;
				bfsQ.push({ nextY,nextX });
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

	vector<string> forestMap(r);

	string line;
	for (int i = 0; i < r; i++) {
		cin >> forestMap[i];
	}

	spotInfo start = { 0,0 }, end = { 0,0 };

	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			if (forestMap[i][j] == 'S') {
				start.y = i;
				start.x = j;
				forestMap[i][j] = '.';
			}
			else if (forestMap[i][j] == 'D') {
				end.y = i;
				end.x = j;
			}
		}
	}

	waterTime[end.y][end.x] = MAX*MAX+1;

	fillWater(forestMap);
	cout << bfs(forestMap, start);
}
*/
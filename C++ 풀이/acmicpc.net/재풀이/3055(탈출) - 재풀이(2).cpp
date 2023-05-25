#include <iostream>
#include <vector>
#include <queue>
#include <string>

using namespace std;

#define MAX 50

struct pos {
	int y, x;
};
int dir[] = { -1,1,0,0 };

int waterVisited[MAX][MAX];
int visited[MAX][MAX] = { {0} };
vector<string> forestMap;

int r, c;

void waterBFS(vector<pos>& waterPos) {
	queue<pos> bfsQ;

	fill(&waterVisited[0][0], &waterVisited[MAX - 1][MAX], MAX * MAX); // 오류1. waterVisited의 초기값을 -1로 처리하면 안됨.

	for (int i = 0; i < waterPos.size(); i++) {
		bfsQ.push({ waterPos[i].y,waterPos[i].x });
		waterVisited[waterPos[i].y][waterPos[i].x] = 0;
	}

	for (; !bfsQ.empty();) {
		int curY = bfsQ.front().y;
		int curX = bfsQ.front().x;
		bfsQ.pop();

		for (int i = 0; i < 4; i++) {
			int nextY = curY + dir[i];
			int nextX = curX + dir[3 - i];

			if (nextY < 0 || nextY >= r || nextX < 0 || nextX >= c) {
				continue;
			}

			if (waterVisited[nextY][nextX] != MAX * MAX) {
				continue;
			}

			if (forestMap[nextY][nextX] == '.' || forestMap[nextY][nextX] == 'S') {
				waterVisited[nextY][nextX] = waterVisited[curY][curX] + 1;
				bfsQ.push({ nextY,nextX });
			}
		}
	}

}

string BFS(pos& start) {
	queue<pos> bfsQ;
	fill(&visited[0][0], &visited[MAX - 1][MAX], -1);

	bfsQ.push({ start.y,start.x });
	visited[start.y][start.x] = 0;

	for (; !bfsQ.empty();) {
		int curY = bfsQ.front().y;
		int curX = bfsQ.front().x;
		bfsQ.pop();

		if (forestMap[curY][curX] == 'D') {
			return to_string(visited[curY][curX]);
		}

		for (int i = 0; i < 4; i++) {
			int nextY = curY + dir[i];
			int nextX = curX + dir[3 - i];


			if (nextY < 0 || nextY >= r || nextX < 0 || nextX >= c) {
				continue;
			}

			if (visited[nextY][nextX] != -1) {
				continue;
			}

			if (forestMap[nextY][nextX] != '.' && forestMap[nextY][nextX] != 'D') {
				continue;
			}

			if (visited[curY][curX] + 1 < waterVisited[nextY][nextX]) { // 오류1. 만약 초기값을 -1로 처리하면 홍수가 벽으로 가로막히는 상황에서 문제가 됨.
				visited[nextY][nextX] = visited[curY][curX] + 1;
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

	forestMap.assign(r, "");

	for (int i = 0; i < r; i++) {
		cin >> forestMap[i];
	}

	vector<pos> waterPos;
	pos start, end;

	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			if (forestMap[i][j] == '*') {
				waterPos.push_back({ i,j });
			}
			else if (forestMap[i][j] == 'S') {
				start = { i,j };
			}
			else if (forestMap[i][j] == 'D') {
				end = { i,j };
			}
		}
	}

	waterBFS(waterPos);

	cout << BFS(start);

	return 0;
}
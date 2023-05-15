#include <iostream>
#include <vector>
#include <queue>
#include <string>

using namespace std;

#define MAX 1000

int dir[] = { -1,1,0,0 };

struct pos {
	int y, x;
};

int w, h;

int fireVisited[MAX][MAX];
int visited[MAX][MAX] = { {0} };

void fireBFS(vector<string>& building, vector<pos>& firePos) {
	queue<pos> bfsQ;

	for (pos p : firePos) {
		bfsQ.push(p);
		fireVisited[p.y][p.x] = 0;
	}

	for (; !bfsQ.empty();) {
		int curY = bfsQ.front().y;
		int curX = bfsQ.front().x;
		bfsQ.pop();

		for (int i = 0; i < 4; i++) {
			int nextY = curY + dir[i];
			int nextX = curX + dir[3 - i];

			if (nextY < 0 || nextY >= h || nextX < 0 || nextX >= w) {
				continue;
			}

			if (building[nextY][nextX] == '#') {
				continue;
			}

			if (fireVisited[nextY][nextX] == MAX * MAX) {
				bfsQ.push({ nextY,nextX });
				fireVisited[nextY][nextX] = fireVisited[curY][curX] + 1;
			}
		}

	}

}

string BFS(vector<string>& building, pos& start) {
	queue<pos> bfsQ;

	bfsQ.push(start);
	visited[start.y][start.x] = 0;

	for (; !bfsQ.empty();) {
		int curY = bfsQ.front().y;
		int curX = bfsQ.front().x;
		bfsQ.pop();

		for (int i = 0; i < 4; i++) {
			int nextY = curY + dir[i];
			int nextX = curX + dir[3 - i];

			if (nextY < 0 || nextY >= h || nextX < 0 || nextX >= w) {
				return to_string(visited[curY][curX] + 1);
			}

			if (visited[nextY][nextX] != -1) { // 실수1. 최단거리 방문을 보장하기 위해 처리해줘야한다. 뺴주니 메모리 초과 오류. 이 부분을 뺏을 때 어떤 문제가 생길지 정확히 파악되지 않는다.
				continue;
			}

			if (building[nextY][nextX] == '#') {
				continue;
			}

			if (visited[curY][curX] + 1 < fireVisited[nextY][nextX]) {
				bfsQ.push({ nextY,nextX });
				visited[nextY][nextX] = visited[curY][curX] + 1;
			}
		}
	}

	return "IMPOSSIBLE";
}

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	int tc;
	cin >> tc;

	vector<string> building;
	vector<pos> firePos;
	pos sang;

	for (; tc--;) {
		cin >> w >> h;

		building.assign(h, "");

		for (int i = 0; i < h; i++) {
			cin >> building[i];
		}

		fill(&fireVisited[0][0], &fireVisited[MAX - 1][MAX], MAX * MAX);
		fill(&visited[0][0], &visited[MAX - 1][MAX], -1);
		firePos.clear();

		for (int i = 0; i < h; i++) {
			for (int j = 0; j < w; j++) {
				if (building[i][j] == '*') {
					firePos.push_back({ i,j });
				}
				else if (building[i][j] == '@') {
					sang = { i,j };
				}
			}
		}

		fireBFS(building, firePos);
		cout << BFS(building, sang) << '\n';
	}

	return 0;
}
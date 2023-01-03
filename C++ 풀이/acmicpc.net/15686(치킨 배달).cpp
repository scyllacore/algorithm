#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

struct pos {
	int y, x;
};

int dy[] = { -1,1,0,0 };
int dx[] = { 0,0,-1,1 };


vector<vector<int>> mapNN;
vector<pos> chicHouse;
vector<pos> pickChicHouse;
int n, m;
int minAns = (int)1e9;

void BFS() {
	int visited[50][50] = { 0 };

	queue<pos> bfsQ;
	int i;

	for (i = 0; i < pickChicHouse.size(); i++) {
		visited[pickChicHouse[i].y][pickChicHouse[i].x] = 1;
		bfsQ.push({ pickChicHouse[i].y ,pickChicHouse[i].x });
	}

	int curY, curX;
	int nextY, nextX;
	int sum = 0;

	while (!bfsQ.empty()) {

		curY = bfsQ.front().y;
		curX = bfsQ.front().x;
		bfsQ.pop();

		for (i = 0; i < 4; i++) {
			nextY = curY + dy[i];
			nextX = curX + dx[i];

			if (nextY < 0 || nextY >= n || nextX < 0 || nextX >= n || visited[nextY][nextX]) continue;

			if (mapNN[nextY][nextX] == 1) sum += visited[curY][curX];

			bfsQ.push({ nextY,nextX });
			visited[nextY][nextX] = visited[curY][curX] + 1;
		}

	}

	minAns = min(sum, minAns);

}

void DFS(int start, int depth) {

	if (depth >= m) {
		BFS();
		return;
	}

	for (int i = start; i < chicHouse.size(); i++) {
		pickChicHouse.push_back(chicHouse[i]);
		DFS(i + 1, depth + 1);
		pickChicHouse.pop_back();
	}
	

}

int main() {

	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> n >> m;

	mapNN.assign(n, vector<int>(n, 0));

	int i, j;
	for (i = 0; i < n; i++) {
		for (j = 0; j < n; j++) {
			cin >> mapNN[i][j];
			if (mapNN[i][j] == 2) {
				chicHouse.push_back({ i,j });
			}
		}
	}

	DFS(0, 0);

	cout << minAns;
	return 0;

}
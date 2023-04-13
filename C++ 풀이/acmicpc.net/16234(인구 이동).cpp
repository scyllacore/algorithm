#include <iostream>
#include <queue>
#include <vector>
#include <cmath>

using namespace std;

#define MAX 50

struct pos {
	int y, x;
};

int dir[] = { -1,1,0,0 };

int n, l, r;

bool visited[MAX][MAX];

bool bfs(vector<vector<int>>& area, int& y, int& x) {

	queue<pos> bfsQ;
	vector<pos> unionSum;

	bfsQ.push({ y,x });
	unionSum.push_back({ y,x });
	visited[y][x] = 1;

	for (; !bfsQ.empty();) {
		int curY = bfsQ.front().y;
		int curX = bfsQ.front().x;
		bfsQ.pop();

		for (int i = 0; i < 4; i++) {
			int nextY = curY + dir[i];
			int nextX = curX + dir[3 - i];

			if (nextY < 0 || nextY >= n || nextX < 0 || nextX >= n) {
				continue;
			}

			int diff = abs(area[curY][curX] - area[nextY][nextX]);

			if (!visited[nextY][nextX] && diff >= l && diff <= r) {
				visited[nextY][nextX] = 1;
				bfsQ.push({ nextY,nextX });
				unionSum.push_back({ nextY, nextX });
			}
		}
	}

	if (unionSum.size() <= 1) {
		return 0;
	}

	int sum = 0;

	for (pos p : unionSum) {
		sum += area[p.y][p.x];
	}
	int avg = sum / unionSum.size();

	for (pos p : unionSum) {
		area[p.y][p.x] = avg;
	}

	return 1;
}

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> n >> l >> r;

	vector<vector<int>> area(n, vector<int>(n));

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> area[i][j];
		}
	}

	int answer = 0;

	for (;;) {

		int count = 0;
		fill(&visited[0][0], &visited[MAX - 1][MAX], 0);

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (!visited[i][j]) { // visited를 언제 초기화 햐아하는지 분석 할 것.
					count += bfs(area, i, j);
				}
			}
		}

		if (count <= 0) {
			break;
		}
		answer++;
	}

	cout << answer;
	return 0;
}
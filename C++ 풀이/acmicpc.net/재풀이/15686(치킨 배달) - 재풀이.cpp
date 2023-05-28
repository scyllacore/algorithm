#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct pos {
	int y, x;
};

int dir[] = { -1,1,0,0 };

int n, m;
vector<vector<int>> chickenMap;
vector<pos> housePos;
vector<pos> chickenPos;
vector<pos> selectedPos;
vector<vector<int>> visited;


int ans = (int)1e6;

void bfs() {
	visited.assign(n, vector<int>(n, 0));

	queue<pos> bfsQ;

	for (pos s : selectedPos) {
		bfsQ.push(s);
		visited[s.y][s.x] = 1;
	}

	for (; !bfsQ.empty();) {
		pos cur = bfsQ.front();
		bfsQ.pop();

		for (int i = 0; i < 4; i++) {
			int nextY = cur.y + dir[i];
			int nextX = cur.x + dir[3 - i];

			if (nextY < 0 || nextY >= n || nextX < 0 || nextX >= n) {
				continue;
			}

			if (!visited[nextY][nextX]) {
				visited[nextY][nextX] = visited[cur.y][cur.x] + 1;
				bfsQ.push({ nextY,nextX });
			}
		}
	}

	int sum = 0;

	for (pos h : housePos) {
		sum += visited[h.y][h.x] - 1;
	}

	ans = min(sum, ans);

	return;
}

void dfs(int start, int depth) {

	if (depth >= m) {
		bfs();
		return;
	}

	for (int i = start; i < chickenPos.size(); i++) {
		selectedPos.push_back(chickenPos[i]);
		dfs(i + 1, depth + 1);
		selectedPos.pop_back();
	}

}

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> n >> m;

	chickenMap.assign(n, vector<int>(n, 0));

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> chickenMap[i][j];
			if (chickenMap[i][j] == 1) {
				housePos.push_back({ i,j });
			}
			else if (chickenMap[i][j] == 2) {
				chickenPos.push_back({ i,j });
			}
		}
	}

	dfs(0, 0);

	cout << ans;

	return 0;
}

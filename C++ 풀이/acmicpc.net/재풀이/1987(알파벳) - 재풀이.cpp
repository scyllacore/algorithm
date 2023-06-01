#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#define SIZE 20

struct pos {
	int y, x;
};

int dir[] = { -1,1,0,0 };

vector<string> board;
bool visited[26] = { 0 };

int r, c;

int ans = 0;

void dfs(pos p, int depth) {
	ans = max(depth, ans);

	visited[board[p.y][p.x] - 'A'] = 1;

	for (int i = 0; i < 4; i++) {
		int nextY = p.y + dir[i];
		int nextX = p.x + dir[3 - i];

		if (nextY < 0 || nextY >= r || nextX < 0 || nextX >= c) {
			continue;
		}

		if (!visited[board[nextY][nextX] - 'A']) {
			dfs({ nextY,nextX }, depth + 1);
		}
	}

	visited[board[p.y][p.x] - 'A'] = 0;
}


int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> r >> c;
	board.assign(r, "");

	for (int i = 0; i < r; i++) {
		cin >> board[i];
	}

	dfs({ 0,0 }, 1);

	cout << ans;
	return 0;
}
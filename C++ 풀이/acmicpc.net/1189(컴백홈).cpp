#include <iostream>
#include <vector>

using namespace std;

#define SIZE 5

struct pos {
	int y, x;
};

int dir[] = { -1,1,0,0 };

bool visited[SIZE][SIZE] = { {0} };
vector<string> mapRC;

int r, c, k;

int ans = 0;

void dfs(pos p, int move) {

	if (p.y == 0 && p.x == c - 1) {
		if (move == k) {
			ans++;
		}

		return;
	}

	for (int i = 0; i < 4; i++) {
		int nextY = p.y + dir[i];
		int nextX = p.x + dir[3 - i];

		if (nextY < 0 || nextY >= r || nextX < 0 || nextX >= c) {
			continue;
		}

		if (visited[nextY][nextX] || mapRC[nextY][nextX] == 'T') {
			continue;
		}

		visited[nextY][nextX] = 1;
		dfs({ nextY,nextX }, move + 1);
		visited[nextY][nextX] = 0;
	}

}

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> r >> c >> k;

	mapRC.assign(r, "");
	for (int i = 0; i < r; i++) {
		cin >> mapRC[i];
	}

	visited[r - 1][0] = 1;
	dfs({ r - 1,0 }, 1);

	cout << ans;

	return 0;
}
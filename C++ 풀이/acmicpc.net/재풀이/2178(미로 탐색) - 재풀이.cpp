#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct pos {
	int y, x;
	int count;
};

int dir[] = { -1,1,0,0 };

int n, m;
vector<string> mirror;
bool visited[100][100] = { {0} };

int bfs() {
	queue<pos> bfsQ;

	bfsQ.push({ 0,0,1 });
	visited[0][0] = 1;

	for (; !bfsQ.empty();) {
		pos curP = bfsQ.front();
		bfsQ.pop();

		if (curP.y == n - 1 && curP.x == m - 1) {
			return curP.count;
		}

		for (int i = 0; i < 4; i++) {
			int nextY = curP.y + dir[i];
			int nextX = curP.x + dir[3 - i];

			if (nextY < 0 || nextY >= n || nextX < 0 || nextX >= m) {
				continue;
			}

			if (mirror[nextY][nextX] == '1' && !visited[nextY][nextX]) {
				visited[nextY][nextX] = 1;
				bfsQ.push({ nextY,nextX,curP.count + 1 });
			}

		}
	}

	return -1;
}

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> n >> m;

	mirror.assign(n, "");

	for (int i = 0; i < n; i++) {
		cin >> mirror[i];
	}

	cout << bfs();

	return 0;
}
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

#define MAX 300

struct pos {
	int y, x;
};
int dir[] = { -1,1,0,0 };

int n, m;
bool visited[MAX][MAX] = { {0} };

bool bfs(pos& start, vector<string>& classroom) {

	fill(&visited[0][0], &visited[MAX - 1][MAX], 0);
	queue<pos> bfsQ;
	bfsQ.push(start);
	visited[start.y][start.x] = 1;

	for (; !bfsQ.empty();) {
		int curY = bfsQ.front().y;
		int curX = bfsQ.front().x;
		bfsQ.pop();

		if (classroom[curY][curX] == '#') {
			return 1;
		}

		for (int i = 0; i < 4; i++) {
			int nextY = curY + dir[i];
			int nextX = curX + dir[3 - i];

			if (nextY < 0 || nextY >= n || nextX < 0 || nextX >= m) {
				continue;
			}

			if (!visited[nextY][nextX] && classroom[nextY][nextX] != '1') {
				bfsQ.push({ nextY,nextX });
			}
			else if (classroom[nextY][nextX] == '1') {
				classroom[nextY][nextX] = '0';
			}
			visited[nextY][nextX] = 1;
		}
	}

	return 0;
}

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> n >> m;

	pos start, end;

	cin >> start.y >> start.x;
	cin >> end.y >> end.x;

	start.y--;
	start.x--;

	vector<string> classroom(n);

	for (int i = 0; i < n; i++) {
		cin >> classroom[i];
	}

	int jumpAns = 0;

	for (;;) {

		jumpAns++;

		if (bfs(start, classroom)) {
			break;
		}
	}

	cout << jumpAns;
	return 0;

}
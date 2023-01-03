#include <iostream>
#include <queue>

using namespace std;

int dy[4] = { -1,1,0,0 };
int dx[4] = { 0,0,-1,1 };

struct pos {
	int y, x;
};

int n;
char picture[100][100];
bool visited[100][100] = { {0} };

void BFS(int y, int x) {

	queue<pos> bfsQ;

	visited[y][x] = 1;
	bfsQ.push({ y,x });

	int curY, curX, nextY, nextX;
	int i;

	while (!bfsQ.empty()) {

		curY = bfsQ.front().y;
		curX = bfsQ.front().x;
		bfsQ.pop();

		for (i = 0; i < 4; i++) {
			nextY = curY + dy[i];
			nextX = curX + dx[i];

			if (nextY < 0 || nextY >= n || nextX < 0 || nextX >= n)
			{
				continue;
			}

			if (!visited[nextY][nextX] && picture[curY][curX] == picture[nextY][nextX]) {
				visited[nextY][nextX] = 1;
				bfsQ.push({ nextY,nextX });
			}

		}

	}

}

int main() {

	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> n;

	int i, j;

	for (i = 0; i < n; i++) {
		for (j = 0; j < n; j++) {
			cin >> picture[i][j];
		}
	}

	int cnt = 0;

	for (i = 0; i < n; i++) {
		for (j = 0; j < n; j++) {
			if (!visited[i][j]) {
				BFS(i, j);
				cnt++;
			}
		}
	}
	cout << cnt << ' ';

	for (i = 0; i < n; i++) {
		fill_n(visited[i], n, 0);
	}

	for (i = 0; i < n; i++) {
		for (j = 0; j < n; j++) {
			if (picture[i][j] == 'R' || picture[i][j] == 'G') {
				picture[i][j] = 'O';
			}
		}
	}


	cnt = 0;

	for (i = 0; i < n; i++) {
		for (j = 0; j < n; j++) {
			if (!visited[i][j]) {
				BFS(i, j);
				cnt++;
			}
		}
	}

	cout << cnt;

	return 0;

}


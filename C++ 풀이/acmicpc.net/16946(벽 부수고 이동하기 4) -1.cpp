#include <iostream>
#include <queue>
#include <vector>
#define MAX 1000

using namespace std;

int mapNM[MAX][MAX];
bool visited[MAX][MAX];

int n, m;

int dy[4] = { -1,1,0,0 };
int dx[4] = { 0,0,-1,1 };

struct pos {
	int y, x;
};

void bfs(int y,int x) {

	queue<pos> bfsQ;
	vector<pos> wall;

	bfsQ.push({ y,x });
	visited[y][x] = 1;

	int curY, curX;
	int nextY, nextX;
	int i, cnt = 1;

	while (!bfsQ.empty()) {
		curY = bfsQ.front().y;
		curX = bfsQ.front().x;
		bfsQ.pop();


		for (i = 0; i < 4; i++) {
			nextY = curY + dy[i];
			nextX = curX + dx[i];

			if (nextY < 0 || nextY >= n || nextX < 0 || nextX >= m) {
				continue;
			}

			if (!mapNM[nextY][nextX] && !visited[nextY][nextX]) {
				visited[nextY][nextX] = 1;
				bfsQ.push({ nextY,nextX });
				cnt++;
			}
			else if (mapNM[nextY][nextX] && !visited[nextY][nextX]) {
				wall.push_back({ nextY,nextX });
				visited[nextY][nextX] = 1;
			}
		}
	}

	for (i = 0; i < wall.size(); i++) {
		mapNM[wall[i].y][wall[i].x] += cnt;
		visited[wall[i].y][wall[i].x] = 0;
	}

}


int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> n >> m;

	string str;
	int i, j;

	for (i = 0; i < n; i++) {
		cin >> str;
		for (j = 0; j < m; j++) {
			if (str[j] == '1') {mapNM[i][j] = 1;}
		}
	}

	for (i = 0; i < n; i++) {
		for (j = 0; j < m; j++) {
			if (!mapNM[i][j] && !visited[i][j]) {
				bfs(i, j);
			}
		}
	}

	for (i = 0; i < n; i++) {
		for (j = 0; j < m; j++) {
			cout << mapNM[i][j]%10;
		}
		cout << '\n';
	}

	return 0;

}

#include <iostream>
#include <queue>
#include <vector>

using namespace std;

#define MAX (int)1e3

struct pos {
	int y, x;
};

int dir[4] = { -1,1,0,0 };

int n, m;
int mapNM[MAX][MAX] = { {0} };
bool visited[MAX][MAX] = { {0} };

void bfs(pos start) {

	queue<pos> bfsQ;
	bfsQ.push(start);
	visited[start.y][start.x] = 1;

	int emptyCnt = 1;

	vector<pos> wallPos;

	for (; !bfsQ.empty();) {
		int curY = bfsQ.front().y;
		int curX = bfsQ.front().x;
		bfsQ.pop();

		for (int i = 0; i < 4; i++) {
			int nextY = curY + dir[i];
			int nextX = curX + dir[3 - i];

			if (nextY < 0 || nextY >= n || nextX < 0 || nextX >= m) {
				continue;
			}

			if (!mapNM[nextY][nextX] && !visited[nextY][nextX]) {
				emptyCnt++;
				visited[nextY][nextX] = 1;
				bfsQ.push({ nextY,nextX });
			}
			else if (mapNM[nextY][nextX] && !visited[nextY][nextX]) {
				visited[nextY][nextX] = 1;
				wallPos.push_back({ nextY,nextX });
			}
		}
	}

	for (int i = 0; i < wallPos.size(); i++) {
		mapNM[wallPos[i].y][wallPos[i].x] += emptyCnt;
		visited[wallPos[i].y][wallPos[i].x] = 0;
	}

}

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> n >> m;

	string tmp;

	for (int i = 0; i < n; i++) {
		cin >> tmp;
		for (int j = 0; j < m; j++) {
			if (tmp[j] == '1') {
				mapNM[i][j] = 1;
			}
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (!mapNM[i][j] && !visited[i][j]) {
				bfs({ i, j });
			}
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cout << mapNM[i][j] % 10;
		}
		cout << '\n';
	}

	return 0;
}
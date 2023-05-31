#include <iostream>
#include <algorithm>

using namespace std;

#define SIZE 100

struct pos {
	int y, x;
};

int dir[] = { -1,1,0,0 };

int n;
int area[SIZE][SIZE] = { {0} };
bool visited[SIZE][SIZE] = { {0} };

void dfs(pos cur) {

	visited[cur.y][cur.x] = 1;

	for (int i = 0; i < 4; i++) {
		int nextY = cur.y + dir[i];
		int nextX = cur.x + dir[3 - i];

		if (nextY < 0 || nextY >= n || nextX < 0 || nextX >= n) {
			continue;
		}

		if (!visited[nextY][nextX]) {
			dfs({ nextY,nextX });
		}
	}

}

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> n;

	int maxH = 0;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> area[i][j];
			maxH = max(area[i][j], maxH);
		}
	}

	int maxArea = 1; // 오류1. 물에 아예 잠기지 않는 상황을 고려해야한다.

	for (int h = 1; h <= maxH; h++) {
		fill(&visited[0][0], &visited[SIZE - 1][SIZE], 0);

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (area[i][j] <= h) {
					visited[i][j] = 1;
				}
			}
		}

		int area = 0;

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (!visited[i][j]) {
					dfs({ i,j });
					area++;
				}
			}
		}

		maxArea = max(area, maxArea);
	}

	cout << maxArea;
	return 0;

}
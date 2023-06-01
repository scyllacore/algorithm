#include <iostream>
#include <vector>

using namespace std;

#define SIZE 100

struct pos {
	int y, x;
};

int dir[] = { -1,1,0,0 };

int n;
vector<string> pic;
bool visited[SIZE][SIZE] = { {0} };
char start;

void dfs(pos p) {
	visited[p.y][p.x] = 1;

	for (int i = 0; i < 4; i++) {
		int nextY = p.y + dir[i];
		int nextX = p.x + dir[3 - i];

		if (nextY < 0 || nextY >= n || nextX < 0 || nextX >= n) {
			continue;
		}

		if (pic[nextY][nextX] == start && !visited[nextY][nextX]) {
			dfs({ nextY,nextX });
		}
	}
}

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> n;
	pic.assign(n, "");

	for (int i = 0; i < n; i++) {
		cin >> pic[i];
	}

	int rgbCnt = 0;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (!visited[i][j]) {
				start = pic[i][j];
				dfs({ i,j });
				rgbCnt++;
			}
		}
	}

	fill(&visited[0][0], &visited[SIZE - 1][SIZE], 0);

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (pic[i][j] == 'G') {
				pic[i][j] = 'R';
			}
		}
	}

	int rbCnt = 0;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (!visited[i][j]) {
				start = pic[i][j];
				dfs({ i,j });
				rbCnt++;
			}
		}
	}

	cout << rgbCnt << ' ' << rbCnt;
	return 0;
}
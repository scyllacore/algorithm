#include <iostream>
#include <vector>
#include <queue>

using namespace std;


int dy[] = { -1,-1,-1,0,0,1,1,1 };
int dx[] = { -1,0,1,-1,1,-1,0,1 };

int area[50][50];
int w, h;

void dfs(int curY, int curX) {

	area[curY][curX] = -1;

	for (int i = 0; i < 8; i++) {
		int nextY = curY + dy[i];
		int nextX = curX + dx[i];

		if (nextY < 0 || nextY >= h || nextX < 0 || nextX >= w) {
			continue;
		}

		if (area[nextY][nextX] == 1) {
			dfs(nextY, nextX);
		}
	}


}

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);


	for (;;) {

		cin >> w >> h;

		if (!(w | h)) {
			break;
		}

		for (int i = 0; i < h; i++) {
			for (int j = 0; j < w; j++) {
				cin >> area[i][j];
			}
		}

		int answer = 0;

		for (int i = 0; i < h; i++) {
			for (int j = 0; j < w; j++) {
				if (area[i][j] == 1) {
					dfs(i, j);
					answer++;
				}
			}
		}

		cout << answer << '\n';


	}

	return 0;

}
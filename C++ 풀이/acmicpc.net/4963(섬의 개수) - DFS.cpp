#include <iostream>

using namespace std;

bool map[51][51] = { {0} };
int dy[8] = { -1,1,0,0,-1,-1,1,1 };
int dx[8] = { 0,0,-1,1,-1,1,-1,1 };
int w, h;


void DFS_btrk(int y, int x) {

	map[y][x] = 0;

	int i, newY, newX;

	for (i = 0; i < 8; i++) {
		newY = y + dy[i];
		newX = x + dx[i];

		if (newY >= 1 && newY <= h && newX >= 1 && newX <= w) {
			if (map[newY][newX]) { DFS_btrk(newY, newX); }
		}

	}


}

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	int i, j;
	int island;

	while (1) {

		cin >> w >> h;

		if (w == 0 && h == 0) {
			return 0;
		}

		island = 0;

		for (i = 0; i < 51; i++) {
			for (j = 0; j < 51; j++) {
				map[i][j] = 0;
			}
		}

		for (i = 1; i <= h; i++) {
			for (j = 1; j <= w; j++) {
				cin >> map[i][j];
			}
		}

		for (i = 1; i <= h; i++) {
			for (j = 1; j <= w; j++) {
				if (map[i][j]) {
					DFS_btrk(i, j);
					island++;
				}
			}
		}

		cout << island << '\n';

	}



}
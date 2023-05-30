#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

#define SIZE 100

struct pos {
	int y, x;
};

int dir[] = { -1,1,0,0 };

int n;
bool mapNN[SIZE][SIZE] = { {0} };
int area[SIZE][SIZE] = { {0} };
int dis[SIZE][SIZE] = { {0} };
int areaN = 1;

void bfsArea(pos start) {
	queue<pos> bfsQ;
	bfsQ.push(start);
	area[start.y][start.x] = -1;

	for (; !bfsQ.empty();) {
		pos curP = bfsQ.front();
		bfsQ.pop();

		for (int i = 0; i < 4; i++) {
			int nextY = curP.y + dir[i];
			int nextX = curP.x + dir[3 - i];

			if (nextY < 0 || nextY >= n || nextX < 0 || nextX >= n) {
				continue;
			}

			if (mapNN[nextY][nextX] && !area[nextY][nextX]) {
				area[nextY][nextX] = -1;
				bfsQ.push({ nextY,nextX });
			}

			if (!mapNN[nextY][nextX]) {
				area[curP.y][curP.x] = areaN;
			}
		}
	}
}

int bfsDis() {

	queue<pos> bfsQ;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (area[i][j] > 0) {
				bfsQ.push({ i,j });
			}
		}
	}

	int ans = (int)1e6;

	for (; !bfsQ.empty();) {
		pos curP = bfsQ.front();
		bfsQ.pop();

		for (int i = 0; i < 4; i++) {
			int nextY = curP.y + dir[i];
			int nextX = curP.x + dir[3 - i];

			if (nextY < 0 || nextY >= n || nextX < 0 || nextX >= n) {
				continue;
			}

			if (!area[nextY][nextX]) {
				area[nextY][nextX] = area[curP.y][curP.x];
				dis[nextY][nextX] = dis[curP.y][curP.x] + 1;
				bfsQ.push({ nextY,nextX });
			}
			else if (area[nextY][nextX] > 0 && area[nextY][nextX] != area[curP.y][curP.x]) {
				ans = min(dis[nextY][nextX] + dis[curP.y][curP.x], ans); // 오류1. 브릿지를 찾자마자 return하면 안된다.
			}
		}
	}

	return ans;
}



int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> n;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> mapNN[i][j];
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (mapNN[i][j] && !area[i][j]) {
				bfsArea({ i,j });
				areaN++;
			}
		}
	}

	/*
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cout.width(3);
			cout <<  area[i][j] << ' ';
		}
		cout << '\n';
	}*/

	cout << bfsDis() << '\n';


	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cout.width(3);
			cout << dis[i][j] << ' ';
		}
		cout << '\n';
	}

	return 0;
}

/*
5

1 0 0 0 1

0 0 0 0 0

0 0 0 0 0

0 0 0 0 0

0 1 0 0 1
*/
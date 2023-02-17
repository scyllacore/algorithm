#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

int dy[] = { -1,1,0,0 };
int dx[] = { 0,0,-1,1 };

int mapNN[100][100];
int n;
int area = 1;

struct pos {
	int y, x;
};

struct posInfo {
	int dis;
	int areaN;
};


void dfs(int y, int x) {

	mapNN[y][x] = -2;

	for (int i = 0; i < 4; i++) {

		int nextY = y + dy[i];
		int nextX = x + dx[i];

		if (nextY < 0 || nextY >= n || nextX < 0 || nextX >= n) {
			continue;
		}

		if (mapNN[nextY][nextX] == 0) {
			mapNN[y][x] = area;
		}

		if (mapNN[nextY][nextX] == -1) {
			dfs(nextY, nextX);
		}
	}

}

int bfs(queue<pos>& bfsQ, vector<vector<posInfo>>& posNN) {
	int answer = (int)1e5;

	for (; !bfsQ.empty();) {

		int curY = bfsQ.front().y;
		int curX = bfsQ.front().x;
		bfsQ.pop();

		for (int i = 0; i < 4; i++) {

			int nextY = curY + dy[i];
			int nextX = curX + dx[i];

			if (nextY < 0 || nextY >= n || nextX < 0 || nextX >= n) {
				continue;
			}

			if (posNN[nextY][nextX].areaN == -2) { //-2구역은 확인하면 안됨.
				continue;
			}

			if (!posNN[nextY][nextX].dis && posNN[nextY][nextX].areaN == 0) {
				posNN[nextY][nextX].dis = posNN[curY][curX].dis + 1;
				posNN[nextY][nextX].areaN = posNN[curY][curX].areaN; // 이걸 빼먹었다.
				bfsQ.push({ nextY,nextX });
			}
			else if (posNN[nextY][nextX].areaN != posNN[curY][curX].areaN) {
				answer = min(posNN[nextY][nextX].dis + posNN[curY][curX].dis, answer);
			}

		}
	}

	return answer;
}


int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> n;

	int i, j;

	for (i = 0; i < n; i++) {
		for (j = 0; j < n; j++) {
			cin >> mapNN[i][j];
			if (mapNN[i][j] == 1) {
				mapNN[i][j] = -1;
			}
		}
	}

	for (i = 0; i < n; i++) {
		for (j = 0; j < n; j++) {
			if (mapNN[i][j] == -1) {
				dfs(i, j);
				area++;
			}
		}
	}

	queue<pos> bfsQ;
	vector<vector<posInfo>> posNN(n, vector<posInfo>(n, { 0,0 }));

	for (i = 0; i < n; i++) {
		for (j = 0; j < n; j++) {
			if (mapNN[i][j] > 0) {
				bfsQ.push({ i,j });
				posNN[i][j] = { 0,mapNN[i][j] };
			}
			else if (mapNN[i][j] == -2) {
				posNN[i][j] = { 0,-2 };
			}
		}
	}

	cout << bfs(bfsQ, posNN);

	return 0;
}

// area변수가 중복 되기 때문에 좋은 코드가 아님. 코드가 더 길어지고 헷갈리는 문제도 있음.
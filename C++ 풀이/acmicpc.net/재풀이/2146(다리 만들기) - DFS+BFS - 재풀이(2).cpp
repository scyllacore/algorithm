#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

struct pos {
	int y, x;
};

int dy[] = { -1,1,0,0 };
int dx[] = { 0,0,-1,1 };

bool mapNN[100][100];
int n;
int area = 1;

int visited[100][100];
int dis[100][100];

void dfs(int y, int x) {

	visited[y][x] = -1;

	for (int i = 0; i < 4; i++) {

		int nextY = y + dy[i];
		int nextX = x + dx[i];

		if (nextY < 0 || nextY >= n || nextX < 0 || nextX >= n) {
			continue;
		}

		if (!mapNN[nextY][nextX]) {
			visited[y][x] = area;
			continue;
		}

		if (mapNN[nextY][nextX] && visited[nextY][nextX] == 0) {
			dfs(nextY, nextX);
		}
	}

}

int bfs(queue<pos>& bfsQ) {
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

			if (!visited[nextY][nextX]) {
				dis[nextY][nextX] = dis[curY][curX] + 1;
				visited[nextY][nextX] = visited[curY][curX];
				bfsQ.push({ nextY,nextX });
			}
			else if (visited[nextY][nextX] >= 1 && visited[nextY][nextX] != visited[curY][curX]) { // -1이 있다는 것을 유의 해야한다. 1보다 큰 조건이 반드시 필요
				answer = min(dis[nextY][nextX] + dis[curY][curX], answer);
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
		}
	}

	for (i = 0; i < n; i++) {
		for (j = 0; j < n; j++) {
			if (mapNN[i][j] && !visited[i][j]) {
				dfs(i, j);
				area++;
			}
		}
	}

	queue<pos> bfsQ;

	for (i = 0; i < n; i++) {
		for (j = 0; j < n; j++) {
			if (visited[i][j] > 0) {
				bfsQ.push({ i,j });
			}
		}
	}

	cout << bfs(bfsQ);

	return 0;
}

//이게 제일 무난하다.
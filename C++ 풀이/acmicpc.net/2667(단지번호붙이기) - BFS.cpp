#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int n;
bool mapNN[25][25] = { {0} };
bool visited[25][25] = { {0} };

int dy[4] = { -1,1,0,0 };
int dx[4] = { 0,0,-1,1 };

struct pos {
	int y, x;
};

int BFS(int y, int x) {

	queue<pos> bfsQ;
	bfsQ.push({ y,x });
	visited[y][x] = 1;
	int cnt = 1;

	int curY, curX;
	int nextY, nextX;
	int i;

	while (!bfsQ.empty()) {
		curY = bfsQ.front().y;
		curX = bfsQ.front().x;
		bfsQ.pop();

		for (i = 0; i < 4; i++) {
			nextY = curY + dy[i];
			nextX = curX + dx[i];

			if (nextY < 0 || nextY >= n || nextX < 0 || nextX >= n) {
				continue;
			}

			if (!visited[nextY][nextX] && mapNN[nextY][nextX]) {
				visited[nextY][nextX] = 1;
				bfsQ.push({ nextY,nextX });
				cnt++;
			}
		}

	}

	return cnt;

}

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> n;

	char ch;
	int i, j;

	for (i = 0; i < n; i++) {
		for (j = 0; j < n; j++) {
			cin >> ch;
			if (ch == '1') mapNN[i][j] = 1;
		}
	}

	vector<int> area;

	for (i = 0; i < n; i++) {
		for (j = 0; j < n; j++) {
			if (!visited[i][j] && mapNN[i][j]) {
				area.push_back(BFS(i, j));
			}
		}
	}

	cout << area.size();
	sort(area.begin(), area.end());

	for (int cnt : area) {
		cout << '\n' << cnt;
	}

	return 0;
}

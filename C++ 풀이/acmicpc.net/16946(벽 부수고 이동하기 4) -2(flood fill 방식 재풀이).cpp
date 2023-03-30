#include <iostream>
#include <queue>
#include <vector>
#include <unordered_set>
#include <unordered_map>

using namespace std;

#define MAX (int)1e3

struct pos {
	int y, x;
};

int dir[4] = { -1,1,0,0 };

int n, m;
int mapNM[MAX][MAX] = { {0} };
int visited[MAX][MAX] = { {0} };

unordered_map<int, int> area;

int bfs(pos start, int& areaNo) {

	queue<pos> bfsQ;
	bfsQ.push(start);
	visited[start.y][start.x] = areaNo;

	int emptyCnt = 1;

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
				visited[nextY][nextX] = areaNo;
				bfsQ.push({ nextY,nextX });
			}
		}
	}

	return emptyCnt;
}

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> n >> m;

	string tmp;

	vector<pos> wallPos;

	for (int i = 0; i < n; i++) {
		cin >> tmp;
		for (int j = 0; j < m; j++) {
			if (tmp[j] == '1') {
				mapNM[i][j] = 1;
				wallPos.push_back({ i,j });
			}
		}
	}

	int areaNo = 1;

	//flood fill
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (!mapNM[i][j] && !visited[i][j]) {
				area[areaNo] = bfs({ i, j }, areaNo);
				areaNo++;
			}
		}
	}

	/*for (auto a : area) {
		cout << a.first << ' ' << a.second << '\n';
	}*/

	//count Moving Spot

	unordered_set<int> dirSet;
	for (int i = 0; i < wallPos.size(); i++) {
		dirSet.clear();

		int curY = wallPos[i].y;
		int curX = wallPos[i].x;

		for (int j = 0; j < 4; j++) {
			int nextY = curY + dir[j];
			int nextX = curX + dir[3 - j]; //  ½Ç¼ö1. dir[j] ¶ó°í ¾¸

			if (nextY < 0 || nextY >= n || nextX < 0 || nextX >= m) {
				continue;
			}

			if (dirSet.find(visited[nextY][nextX]) != dirSet.end()) {
				continue;
			}

			mapNM[curY][curX] += area[visited[nextY][nextX]];
			dirSet.insert(visited[nextY][nextX]);
		}
	}


	//print
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cout << mapNM[i][j] % 10;
		}
		cout << '\n';
	}

	return 0;
}
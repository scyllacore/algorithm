#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

struct pos {
	int y, x;
};

int dir[] = { -1,1,0,0 };

int n;

vector<string> mapNN;
bool visited[25][25] = { {0} };

int bfs(pos start) {
	int count = 1;

	queue<pos> bfsQ;
	bfsQ.push(start);
	visited[start.y][start.x] = 1;

	for (; !bfsQ.empty();) {
		pos curP = bfsQ.front();
		bfsQ.pop();

		for (int i = 0; i < 4; i++) {
			int nextY = curP.y + dir[i];
			int nextX = curP.x + dir[3 - i];

			if (nextY < 0 || nextY >= n || nextX < 0 || nextX >= n) {
				continue;
			}

			if (mapNN[nextY][nextX] == '1' && !visited[nextY][nextX]) {
				visited[nextY][nextX] = 1;
				bfsQ.push({ nextY,nextX });
				count++;
			}

		}
	}

	return count;
}

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> n;

	mapNN.assign(n, "");

	for (int i = 0; i < n; i++) {
		cin >> mapNN[i];
	}

	vector<int> ans;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (mapNN[i][j] == '1' && !visited[i][j]) {
				ans.push_back(bfs({ i,j }));
			}
		}
	}

	sort(ans.begin(), ans.end());

	cout << ans.size() << '\n';

	for (int cnt : ans) {
		cout << cnt << '\n';
	}

	return 0;
}
#include <iostream>
#include <queue>
#include <vector>
#include <cmath>

using namespace std;

#define MAX 50

struct pos {
	int y, x;
};

int dir[] = { -1,1,0,0 };

int n, l, r;

int area[MAX][MAX];
bool visited[MAX][MAX];

bool bfs(int& y, int& x) {
	/*
	오류1. 당일 연합으로 지정되어 방문처리가 된 곳은 더 이상 방문할 수 없음을 유의해야한다.
	만약 이곳에서 초기화를 하면 한 지점을 방문할 때 마다 초기화가 이루어 짐으로,
	이미 방문한 곳을 재방문한다. 그래서 하루동안 만들 수 있는 연합을 제대로 처리 할 수 없다.
	"국경선이 열려있어 인접한 칸만을 이용해 이동할 수 있으면, 그 나라를 오늘 하루 동안은 연합이라고 한다.
	하루가 마무리되면 연합을 해체하고, 모든 국경선을 닫는다."
	*/

	queue<pos> bfsQ;
	vector<pos> posV;

	bfsQ.push({ y,x });
	posV.push_back({ y,x });
	visited[y][x] = 1;

	for (; !bfsQ.empty();) {
		int curY = bfsQ.front().y;
		int curX = bfsQ.front().x;
		bfsQ.pop();

		for (int i = 0; i < 4; i++) {
			int nextY = curY + dir[i];
			int nextX = curX + dir[3 - i];

			if (nextY < 0 || nextY >= n || nextX < 0 || nextX >= n) {
				continue;
			}

			int diff = abs(area[curY][curX] - area[nextY][nextX]);

			if (!visited[nextY][nextX] && diff >= l && diff <= r) {
				bfsQ.push({ nextY,nextX });
				posV.push_back({ nextY,nextX });
				visited[nextY][nextX] = 1;
			}
		}
	}

	if (posV.size() <= 1) {
		return 0;
	}

	int sum = 0;

	for (pos v : posV) {
		sum += area[v.y][v.x];
	}

	int avg = sum / posV.size();

	for (pos v : posV) {
		area[v.y][v.x] = avg;
	}

	return 1;
}

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> n >> l >> r;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> area[i][j];
		}
	}

	int ans = 0;

	for (;;) {

		//오류1. 하루 단위로 모든 지점에 대해 연합 여부를 확인하고 visited를 초기화 해야한다.
		fill(&visited[0][0], &visited[MAX - 1][MAX], 0);

		int res = 0;

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (!visited[i][j]) {
					res += bfs(i, j);
				}
			}
		}

		if (res <= 0) {
			break;
		}

		ans++;
	}

	cout << ans;
	return 0;
}
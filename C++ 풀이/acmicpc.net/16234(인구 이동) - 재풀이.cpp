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
	����1. ���� �������� �����Ǿ� �湮ó���� �� ���� �� �̻� �湮�� �� ������ �����ؾ��Ѵ�.
	���� �̰����� �ʱ�ȭ�� �ϸ� �� ������ �湮�� �� ���� �ʱ�ȭ�� �̷�� ������,
	�̹� �湮�� ���� ��湮�Ѵ�. �׷��� �Ϸ絿�� ���� �� �ִ� ������ ����� ó�� �� �� ����.
	"���漱�� �����־� ������ ĭ���� �̿��� �̵��� �� ������, �� ���� ���� �Ϸ� ������ �����̶�� �Ѵ�.
	�Ϸ簡 �������Ǹ� ������ ��ü�ϰ�, ��� ���漱�� �ݴ´�."
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

		//����1. �Ϸ� ������ ��� ������ ���� ���� ���θ� Ȯ���ϰ� visited�� �ʱ�ȭ �ؾ��Ѵ�.
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
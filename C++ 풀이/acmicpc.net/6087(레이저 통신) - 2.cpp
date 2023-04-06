#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

#define MAX 100
#define DIR_TYPE 4

struct spotInfo {
	int y, x;
};

int dir[] = { -1,1,0,0 };

vector<vector<char>> board;
int w, h;
int visited[MAX][MAX] = { {0} };

bool isTrueSpot(int y, int x) {
	return y >= 0 && y < h&& x >= 0 && x < w&& board[y][x] != '*';
}

int bfs(spotInfo& start, spotInfo& end) {

	queue<spotInfo> bfsQ;
	bfsQ.push(start);
	visited[start.y][start.x] = 1;

	for (; !bfsQ.empty();) {
		int curY = bfsQ.front().y;
		int curX = bfsQ.front().x;
		bfsQ.pop();

		for (int i = 0; i < DIR_TYPE; i++) {
			int nextY = curY + dir[i];
			int nextX = curX + dir[3 - i];

			for (; isTrueSpot(nextY, nextX);) {
				if (!visited[nextY][nextX]) {
					visited[nextY][nextX] = visited[curY][curX] + 1;
					bfsQ.push({ nextY,nextX });
				}

				nextY += dir[i];
				nextX += dir[3 - i];
			}
		}
	}

	return visited[end.y][end.x] - 2;
	// visited�� �̵� Ƚ���� �����Ѵ�.�ſ��� ������ �̵� Ƚ�� - 1�̴�.
	// �׷��� ���� -1�� ����� �ϴµ�, visited�� �湮 ó���� ���ҵ� �ϵ��� �ʱ⿡ 0�� �ƴ� 1�� �����ϰ� �صξ���.
	// �ᱹ ���� �̵�Ƚ���� 0���� �����ؾ� �ϴµ� 1���� �����ϰ� �ȴ�.
	// ���� -2�� �ؾ��Ѵ�.
}

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> w >> h;

	board.assign(h, vector<char>(w));

	vector<spotInfo> cSpot;

	string tmp;

	for (int i = 0; i < h; i++) {
		cin >> tmp;
		for (int j = 0; j < w; j++) {
			board[i][j] = tmp[j];

			if (board[i][j] == 'C') {
				cSpot.push_back({ i,j });
				board[i][j] = '.';
			}
		}
	}

	cout << bfs(cSpot[0], cSpot[1]);

	return 0;
}
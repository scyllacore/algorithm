#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct pos {
	int y, x;
};

int dy[] = { -1,-1,-1,0,0,1,1,1 };
int dx[] = { -1,0,1,-1,1,-1,0,1 };

int area[50][50]; 
// bool을 쓰고 -1대신 0을 써도 된다. 
//그러나 역할을 헷갈릴 수도 있으니 -1을 되도록이면 사용하고, 
//배열 크기를 크게 설정해야하는 경우 bool을 사용할 수 있다면 사용한다.
int w, h;

void bfs(int y, int x) {

	queue<pos> bfsQ;
	area[y][x] = -1;
	bfsQ.push({ y,x });

	for (; !bfsQ.empty();) {
		int curY = bfsQ.front().y;
		int curX = bfsQ.front().x;
		bfsQ.pop();

		for (int i = 0; i < 8; i++) {
			int nextY = curY + dy[i];
			int nextX = curX + dx[i];

			if (nextY < 0 || nextY >= h || nextX < 0 || nextX >= w) {
				continue;
			}

			if (area[nextY][nextX] == 1) {
				area[nextY][nextX] = -1;
				bfsQ.push({ nextY,nextX });
			}


		}

	}


}

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);


	for (;;) {

		cin >> w >> h;

		if (!(w | h)) {
			break;
		}

		for (int i = 0; i < h; i++) {
			for (int j = 0; j < w; j++) {
				cin >> area[i][j];
			}
		}

		int answer = 0;

		for (int i = 0; i < h; i++) {
			for (int j = 0; j < w; j++) {
				if (area[i][j] == 1) {
					bfs(i, j);
					answer++;
				}
			}
		}

		cout << answer << '\n';


	}

	return 0;

}
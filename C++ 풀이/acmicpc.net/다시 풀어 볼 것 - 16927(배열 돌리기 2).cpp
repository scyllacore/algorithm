#include <iostream>
#include <algorithm>

using namespace std;

int map[301][301];
int N, M, R;

int dy[4] = { 0,1,0,-1 };
int dx[4] = { 1,0,-1,0 };

void rotate(int start, int len) {
	int r = R % len;
	for (int i = 0; i < r; i++) {

		int startVal = map[start][start];
		int y = start;
		int x = start;

		for (int k = 0; k < 4;) {

			int ny = y + dy[k];
			int nx = x + dx[k];

			if (ny == start && nx == start) break;
			if (start <= ny && ny < N - start && start <= nx && nx < M - start) {
				map[y][x] = map[ny][nx];
				y = ny;
				x = nx;

			}
			else {
				k++;
			}
		}
		map[start + 1][start] = startVal;
	}

}


int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> N >> M >> R;

	int i, j;

	for (i = 0; i < N; i++) {
		for (j = 0; j < M; j++) {
			cin >> map[i][j];
		}
	}

	int cnt = min(N, M) / 2;

	for (i = 0; i < cnt; i++) {
		rotate(i, 2 * (N - 2 * i) + 2 * (M - 2 * i) - 4);
	}


	for (i = 0; i < N; i++) {
		for (j = 0; j < M; j++) {
			cout << map[i][j] << ' ';
		}
		cout << '\n';
	}

	return 0;
}
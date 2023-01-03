	#include <iostream>
	#include <queue>

	using namespace std;

	bool cheeseBoard[100][100] = { {0} };
	int visited[100][100];
	int n, m;

	struct pos {
		int y, x;
	};

	int dy[] = { -1,1,0,0 };
	int dx[] = { 0,0,-1,1 };

	int calMeltTimeBFS(int cheeseCnt) {

		int meltTime = 0;

		for (; cheeseCnt > 0;) {

			fill(&visited[0][0], &visited[99][100], 0);

			queue<pos> bfsQ;

			bfsQ.push({ 0,0 });
			visited[0][0] = -1;

			int curY, curX;
			int nextY, nextX;

			while (!bfsQ.empty()) {

				curY = bfsQ.front().y;
				curX = bfsQ.front().x;
				bfsQ.pop();

				for (int i = 0; i < 4; i++) {
					nextY = curY + dy[i];
					nextX = curX + dx[i];

					if (nextY < 0 || nextY >= n || nextX < 0 || nextX >= m || visited[nextY][nextX] == 2) continue;

					if (!visited[nextY][nextX]) {
						if (!cheeseBoard[nextY][nextX]) {
							visited[nextY][nextX] = -1;
							bfsQ.push({ nextY,nextX });
						}
						else {
							visited[nextY][nextX] = 1;
						}
					}
					else if (visited[nextY][nextX] == 1) {
						visited[nextY][nextX] = 2; 
						//처음 제출한 코드에 대해 오류 분석하고 위 코드 이해할 것.
						//녹을 치즈에 대해서 다시 방문할 필요가 없음.
						cheeseBoard[nextY][nextX] = 0;
						cheeseCnt--;
					}
				}
			}

			meltTime++;
		}

		return meltTime;

	}

	int main() {
		cin.tie(NULL);
		cout.tie(NULL);
		ios::sync_with_stdio(false);

		cin >> n >> m;

		int i, j;
		int totalCheese = 0;



		for (i = 0; i < n; i++) {
			for (j = 0; j < m; j++) {
				cin >> cheeseBoard[i][j];
				if (cheeseBoard[i][j]) { totalCheese++; }
			}
		}

		cout << calMeltTimeBFS(totalCheese);

		return 0;

	}


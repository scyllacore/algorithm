#include <iostream>
#include <queue>

using namespace std;

int w, h;
bool mapNM[50][50]={{0}};
bool visited[50][50] ={{0}};

int dy[8] = { -1,-1,-1,0,0,1,1,1 };
int dx[8] = { -1,0,1,-1,1,-1,0,1 };

struct pos {
	int y, x;
};

void BFS(int y,int x){

	queue<pos> bfsQ;

	visited[y][x] = 1;
	bfsQ.push({ y,x });

	int curY, curX;
	int nextY, nextX;
	int i;

	while (!bfsQ.empty()) {

		curY = bfsQ.front().y;
		curX = bfsQ.front().x;
		bfsQ.pop();

		for (i = 0; i < 8; i++) {
			nextY = curY + dy[i];
			nextX = curX + dx[i];

			if (nextY < 0 || nextY >= h || nextX < 0 || nextX >= w) { continue; }

			if (!visited[nextY][nextX] && mapNM[nextY][nextX]) {
				visited[nextY][nextX] = 1;
				bfsQ.push({ nextY,nextX });
			}

		}

	}

}

int main() {

	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	int i, j;
	int islandCnt;

	while (1) {

		cin >> w >> h;
		if (w == 0 && h == 0) { break; }

		for (i = 0; i < h; i++) {
			for (j = 0; j < w; j++) {
				cin >> mapNM[i][j];
			}
		}

		islandCnt = 0;

		for (i = 0; i < h; i++) {
			for (j = 0; j < w; j++) {
				if (!visited[i][j] && mapNM[i][j]) {
					BFS(i,j);
					islandCnt++;
				}
			}
		}

		cout << islandCnt << '\n';
		fill(&visited[0][0], &visited[49][50],0);
		
	}


}

#include <iostream>
#include <vector>

using namespace std;

int n, m;
vector<string> board;

bool flag;
bool visited[50][50];

int startY, startX;

int dy[] = { -1,1,0,0 };
int dx[] = { 0,0,-1,1 };


void DFS(int curY, int curX, int preY, int preX) {

	if (flag == 1) return;

	int i;
	int nextY, nextX;

	for (i = 0; i < 4; i++) {

		nextY = curY + dy[i];
		nextX = curX + dx[i];

		if (nextY < 0 || nextY >= n || nextX < 0 || nextX >= m) continue;

		if (nextY == preY && nextX == preX) continue; // 실수 1. nextY == preX
		 
		if (nextY == startY && nextX == startX) { flag = 1; return; }//실수 2. flag==1 

		if (!visited[nextY][nextX] && board[curY][curX] == board[nextY][nextX]) {
			visited[nextY][nextX] = 1;
			DFS(nextY, nextX, curY, curX);
			visited[nextY][nextX] = 0;
		}

	}

}

bool checkCycle() {

	int i, j;

	fill(&visited[0][0], &visited[49][50], 0);
	flag = 0;

	for (i = 0; i < n; i++) {
		for (j = 0; j < m; j++) {

			startY = i, startX = j;

			visited[i][j] = 1;
			DFS(i, j, i, j);
			visited[i][j] = 0;

			if (flag == 1) {return 1;}

		}
	}

	return 0;

}

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> n >> m;

	string tmp;
	int i;

	for (i = 0; i < n; i++) {
		cin >> tmp;
		board.push_back(tmp);
	}

	cout << (checkCycle() ? "Yes" : "No");

}

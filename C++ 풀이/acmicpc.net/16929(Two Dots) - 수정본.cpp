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


bool DFS(int curY, int curX, int preY, int preX) {

	int i;
	int nextY, nextX;

	for (i = 0; i < 4; i++) {

		nextY = curY + dy[i];
		nextX = curX + dx[i];

		if (nextY < 0 || nextY >= n || nextX < 0 || nextX >= m) continue;

		if (nextY == preY && nextX == preX) continue;

		if (nextY == startY && nextX == startX) {return 1;} 

		if (!visited[nextY][nextX] && board[curY][curX] == board[nextY][nextX]) {
			visited[nextY][nextX] = 1;
			if (DFS(nextY, nextX, curY, curX)) { return 1; }
			visited[nextY][nextX] = 0;
		}

	}

	return 0;

}

bool checkCycle() {

	int i, j;

	fill(&visited[0][0], &visited[49][50], 0);

	for (i = 0; i < n; i++) {
		for (j = 0; j < m; j++) {

			startY = i, startX = j;

			visited[i][j] = 1;
			if (DFS(i, j, i, j)) {return 1;}
			visited[i][j] = 0;

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

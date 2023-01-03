#include <iostream>
#include <algorithm>

using namespace std;

string board[20];

int r, c;

int ans = 1;
bool alphaCnt[26] = { 0 };

int dy[] = { -1,1,0,0 };
int dx[] = { 0,0,-1,1 };


void DFS_btrk(int y, int x, int move) {

	ans = max(move, ans);

	int i;
	int nextY, nextX;

	for (i = 0; i < 4; i++) {
		nextY = y + dy[i];
		nextX = x + dx[i];

		if (nextY < 0 || nextY >= r || nextX < 0 || nextX >= c) {
			continue;
		}

		if (!alphaCnt[board[nextY][nextX] - 'A']) {
			alphaCnt[board[nextY][nextX] - 'A'] = 1;
			DFS_btrk(nextY, nextX, move + 1);
			alphaCnt[board[nextY][nextX] - 'A'] = 0;
		}
	}



}

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> r >> c;

	for (int i = 0; i < r; i++) {
		cin >> board[i];
	}

	alphaCnt[board[0][0] - 'A'] = 1;
	DFS_btrk(0, 0, 1);

	cout << ans;

	return 0;

}
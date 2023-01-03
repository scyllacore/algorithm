#include <iostream>

using namespace std;

bool paper[128][128] = { {0} };
int paperCnt[2] = { 0 };

bool sameCheck(int y, int x, int size) {

	int i, j;

	for (i = y; i < y + size; i++) {
		for (j = x; j < x + size; j++) {
			if (paper[y][x] != paper[i][j]) return 0;
		}
	}

	return 1;
}

void DFS_btrk(int y, int x, int size) {

	if (sameCheck(y, x, size)) {
		paperCnt[paper[y][x]]++;
		return;
	}

	DFS_btrk(y, x, size / 2);
	DFS_btrk(y, x + size / 2, size / 2);
	DFS_btrk(y + size / 2, x, size / 2);
	DFS_btrk(y + size / 2, x + size / 2, size / 2);

}


int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	int n;
	cin >> n;

	int i, j;
	char ch;

	for (i = 0; i < n; i++) {
		for (j = 0; j < n; j++) {
			cin >> ch;
			if (ch == '1') { paper[i][j] = 1; }
		}
	}

	DFS_btrk(0, 0, n);

	cout << paperCnt[0] << '\n';
	cout << paperCnt[1];

	return 0;

}
#include <iostream>

using namespace std;

bool screen[64][64] = { {0} };

bool sameCheck(int y, int x, int size) {

	int i, j;

	for (i = y; i < y + size; i++) {
		for (j = x; j < x + size; j++) {
			if (screen[y][x] != screen[i][j]) return 0;
		}
	}
	return 1;
}

void quadTree(int y, int x, int size) {

	if (sameCheck(y, x, size)) {
		cout << screen[y][x];
		return;
	}

	cout << '(';
	quadTree(y, x, size / 2);
	quadTree(y, x + size / 2, size / 2);
	quadTree(y + size / 2, x, size / 2);
	quadTree(y + size / 2, x + size / 2, size / 2);
	cout << ')';

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
			if (ch == '1') { screen[i][j] = 1; }
		}
	}

	quadTree(0, 0, n);

	return 0;
}
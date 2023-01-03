#include <iostream>

using namespace std;

#define MAX 3072

bool starMap[MAX][MAX * 2] ={{0}};

void star(int y, int x, int n) {

	if (n == 3) {

		starMap[y][x] = 1;
		starMap[y + 1][x - 1] = starMap[y + 1][x + 1] = 1;
		starMap[y + 2][x - 2] = starMap[y + 2][x - 1] = starMap[y + 2][x] = starMap[y + 2][x + 1] = starMap[y + 2][x + 2] = 1;
		return;
	}

	star(y, x, n / 2);
	star(y + n / 2, x - n / 2, n / 2);
	star(y + n / 2, x + n / 2, n / 2);

}

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	int n;
	cin >> n;

	star(0, n - 1, n);

	int i, j;

	for (i = 0; i < n; i++) {
		for (j = 0; j < 2 * n - 1; j++) {
			cout << (starMap[i][j] ? '*' : ' ');
		}
		cout << '\n';
	}

	return 0;

}


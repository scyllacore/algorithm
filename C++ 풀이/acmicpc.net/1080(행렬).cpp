#include <cstdio>

using namespace std;

bool matrix[50][50], matrixAns[50][50];

int n, m;

void change(int y, int x) {

	int i, j;

	for (i = y; i < y + 3; i++) {
		for (j = x; j < x + 3; j++) {
			matrix[i][j] = !matrix[i][j];
		}
	}
}

bool sameCheck() {

	int i, j;

	for (i = 0; i < n; i++) {
		for (j = 0; j < m; j++) {
			if (matrix[i][j] != matrixAns[i][j])
				return 0;
		}
	}

	return 1;

}



void input() {

	scanf("%d %d", &n, &m);

	int i, j;

	for (i = 0; i < n; i++) {
		for (j = 0; j < m; j++) {
			scanf("%1d", &matrix[i][j]);
		}
	}

	for (i = 0; i < n; i++) {
		for (j = 0; j < m; j++) {
			scanf("%1d", &matrixAns[i][j]);
		}
	}

}


int main() {

	input();

	int ansCnt = 0;
	int i, j;


	for (i = 0; i <= n - 3; i++) {
		for (j = 0; j <= m - 3; j++) {
			if (matrix[i][j] != matrixAns[i][j]) {
				change(i, j);
				ansCnt++;
			}
		}
	}

	if (sameCheck()) { printf("%d", ansCnt); }
	else { printf("-1"); }


}

//최종본
#include <iostream>

using namespace std;

#define MAX 50

int n, m;
bool matrixA[MAX][MAX] = { {0} };
bool matrixB[MAX][MAX] = { {0} };

bool isSameMatrix() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (matrixA[i][j] != matrixB[i][j]) {
				return 0;
			}
		}
	}
	return 1;
}

void change3x3(int y, int x) {

	for (int i = y; i < y + 3; i++) {
		for (int j = x; j < x + 3; j++) {
			matrixA[i][j] = !matrixA[i][j];
		}
	}
}

int changeMatrix() {
	int count = 0;

	for (int i = 0; i <= n - 3; i++) {
		for (int j = 0; j <= m - 3; j++) {

			if (matrixA[i][j] == matrixB[i][j]) {
				continue;
			}

			change3x3(i, j);
			count++;
		}
	}

	if (isSameMatrix()) {
		return count;
	}

	return -1;
}

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> n >> m;

	string line;

	for (int i = 0; i < n; i++) {
		cin >> line;
		for (int j = 0; j < m; j++) {
			matrixA[i][j] = line[j] - '0';
		}
	}

	for (int i = 0; i < n; i++) {
		cin >> line;
		for (int j = 0; j < m; j++) {
			matrixB[i][j] = line[j] - '0';
		}
	}

	cout << changeMatrix();
	return 0;

}


//행렬을 바꿀 때 마다 검사하는 것이 아닌, 바꿀 수 있는 부분을 다 바꾼 후 검사 하는 것이 효율적이다.
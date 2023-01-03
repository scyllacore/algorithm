#include <iostream>

using namespace std;

int paper[2187][2187];
int paperType[3] = { 0 };

bool checkSameN(int y, int x, int size) {
	int i, j;
	bool flag = 0;

	for (i = 0; i < size; i++) {
		for (j = 0; j < size; j++) {
			if (paper[y][x] != paper[y + i][x + j]) {
				return 0;
			}
		}
	}
	return 1;
}


void DFS(int y, int x, int size) {

	int i, j;

	if (checkSameN(y,x,size)) {
		paperType[paper[y][x] + 1]++;
	
	}
	else {
		for (i = 0; i < 3; i++) {
			for (j = 0; j < 3; j++) {
				DFS(y + i * size / 3, x + j * size / 3, size / 3);
			}
		}
	}
}

int main() {

	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	int n;

	cin >> n;

	int i, j;

	for (i = 0; i < n; i++) {
		for (j = 0; j < n; j++) {
			cin >> paper[i][j];
		}
	}

	DFS(0, 0, n);
	
	for (i = 0; i < 3; i++) {
		cout << paperType[i] << '\n';
	}

	return 0;

}


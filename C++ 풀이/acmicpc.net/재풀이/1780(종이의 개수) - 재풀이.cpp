#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> paper;

int paperCount[3] = { 0 };

bool isSameNumberPaper(int y, int x, int size) {
	for (int i = y; i < y + size; i++) {
		for (int j = x; j < x + size; j++) {
			if (paper[y][x] != paper[i][j]) {
				return 0;
			}
		}
	}

	return 1;
}

void searchPaper(int y, int x, int size) {
	/*if (size <= 1) {
		paperCount[paper[y][x] + 1]++; // 아래 if문에서 검사하기 때문에 필요 없다.
		return;
	}*/

	if (isSameNumberPaper(y, x, size)) {
		paperCount[paper[y][x] + 1]++;
		return;
	}

	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			searchPaper(y + i * size / 3, x + j * size / 3, size / 3);
		}
	}

}

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	int n;
	cin >> n;

	paper.assign(n, vector<int>(n));

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> paper[i][j];
		}
	}

	searchPaper(0, 0, n);

	for (int i = 0; i < 3; i++) {
		cout << paperCount[i] << '\n';
	}

	return 0;
}
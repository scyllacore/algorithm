#include <iostream>

using namespace std;

bool cabbage[50][50] = { {0} };
int tc;
int m, n, k;

void cabbageCheck(int y, int x) {

	cabbage[y][x] = 0;

	if (x + 1 < m && cabbage[y][x + 1] == 1) {
		cabbageCheck(y, x + 1);
	}
	if (x - 1 >= 0 && cabbage[y][x - 1] == 1) {
		cabbageCheck(y, x - 1);
	}
	if (y + 1 < n && cabbage[y + 1][x] == 1) {
		cabbageCheck(y + 1, x);
	}
	if (y - 1 >= 0 && cabbage[y - 1][x] == 1) {
		cabbageCheck(y - 1, x);
	}

}


int main() {

	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> tc;

	int i, j;
	int x, y;
	int minBug;

	while ((tc--) > 0) {

		cin >> m >> n >> k;

		for (i = 0; i < k; i++) {
			cin >> x >> y;
			cabbage[y][x] = 1;
		}

		minBug = 0;

		for (i = 0; i < n; i++) {
			for (j = 0; j < m; j++) {
				if (cabbage[i][j] == 1) {
					cabbageCheck(i, j);
					minBug++;
				}
			}
		}

		cout << minBug << '\n';
		fill(&cabbage[0][0], &cabbage[49][50], 0);
		//다 쓰면 메모리 초기화를 하자!

		//압축버전 : 초기 입력 배열에서 확인한 곳은 0으로 만들어서 그 뒤에 확인 안하도록
	}

	return 0;

}
#include <iostream>
#include <algorithm>

using namespace std;

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	int n;
	cin >> n;

	bool coinBoard[20][20] ={{0}};

	int i, j;
	char ch;

	for (i = 0; i < n; i++) {
		for (j = 0; j < n; j++) {
			cin >> ch;
			if (ch == 'T') { coinBoard[i][j] = 1; }
		}
	}
	
	int ans = 999, sumT,tail;
	int y, x;
	bool tmp;

	for (i = 0; i < (1 << n); i++) { // 행을 뒤집는 경우의 수

		sumT = 0;

		for (x = 0; x < n; x++) {

			tail = 0;
			
			for (y = 0; y < n; y++) {

				tmp = coinBoard[y][x];

				if (i & (1 << y)) { tmp = !tmp; } // 뒤집은 행에 대해 세로(열)순서로 읽음 
				if (tmp) { tail++; }
			}

			sumT += min(tail, n - tail);
		}
		ans = min(sumT, ans);
	}


	cout << ans;
	return 0;

}
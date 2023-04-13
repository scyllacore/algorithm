#include <iostream>
#include <algorithm>

using namespace std;

#define MAX 20

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	int n;
	cin >> n;

	bool table[MAX][MAX] = { {0} };

	char ch;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> ch;
			if (ch == 'T') {
				table[i][j] = 1;
			}
		}
	}

	int ans = MAX * MAX, sumT;
	bool coinSpot;

	for (int bitCase = 1; bitCase < (1 << n); bitCase++) {

		sumT = 0;

		for (int x = 0; x < n; x++) {
			int tail = 0;

			for (int y = 0; y < n; y++) {
				coinSpot = table[y][x];

				if (bitCase & (1 << y)) {
					coinSpot = !coinSpot;
				}
				if (coinSpot) {
					tail++;
				}
			}
			sumT += min(tail, n - tail);
		}
		ans = min(sumT, ans);
	}

	cout << ans;
	return 0;
}
#include <iostream>

using namespace std;

#define MAX 6561

bool starMap[MAX][MAX] ={{0}};

void star(int y, int x, int n) {

	if (n == 3) {
		
		int i, j;
		for (i = 0; i < 3; i++) {
			for (j = 0; j < 3; j++) {
				starMap[y + i][x + j] = 1;
			}
		}
		starMap[y + 1][x + 1] = 0;
		return;
	}

	star(y, x, n / 3);
	star(y, x + n / 3, n / 3);
	star(y, x + (n / 3)*2, n / 3);
	
	star(y+ n / 3, x, n / 3);
	star(y+ n / 3, x + (n / 3) * 2, n / 3);

	star(y + (n / 3) * 2, x, n / 3);
	star(y + (n / 3) * 2, x + n / 3, n / 3);
	star(y + (n / 3) * 2, x + (n / 3) * 2, n / 3);

}

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	int n;
	cin >> n;


	star(0, 0, n);

	int i, j;

	for (i = 0; i < n; i++) {
		for (j = 0; j < n; j++) {
			cout << (starMap[i][j] ? '*' : ' ');
		}
		cout << '\n';
	}


	return 0;

}


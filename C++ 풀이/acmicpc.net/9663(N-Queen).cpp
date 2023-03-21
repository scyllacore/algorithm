#include <iostream>
#include <cmath>

using namespace std;

int n, ans = 0;
int col[16];

bool checkQueen(int xDepth) {

	for (int i = 1; i < xDepth; i++) {
		if (col[xDepth] == col[i]
			|| (abs(col[xDepth] - col[i]) == xDepth - i)) {
			return 0;
		}
	}

	return 1;
}

void nQueen_DFS(int xDepth) {

	if (xDepth > n) {
		ans++;
		return;
	}

	for (int i = 1; i <= n; i++) {
		col[xDepth] = i;

		if (checkQueen(xDepth)) {
			nQueen_DFS(xDepth + 1);
		}

	}


}

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> n;

	nQueen_DFS(1);

	cout << ans;

	return 0;

}
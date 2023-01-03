#include <iostream>
#include <cmath>

using namespace std;

int n, ans = 0;
int col[16];

bool checkQueen(int depth) {

	for (int i = 1; i < depth; i++) {
		if (col[depth] == col[i] || (abs(col[depth] - col[i]) == depth - i)) return 0;
	}

	return 1;
}

void nQueen_DFS(int depth) {

	if (depth > n) {
		ans++;
		return;
	}

	for (int i = 1; i <= n; i++) {
		col[depth] = i;

		if (checkQueen(depth)) {
			nQueen_DFS(depth + 1);
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
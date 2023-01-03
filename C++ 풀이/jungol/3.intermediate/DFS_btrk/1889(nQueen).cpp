#include <iostream>
#include <cmath>

using namespace std;

int col[14];
int n,ans=0;

bool check(int depth) {

	for (int i = 1; i < depth; i++) {
		if (col[depth] == col[i] || depth - i == abs(col[depth] - col[i])) return 0;
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
		if (check(depth)) {
			nQueen_DFS(depth + 1);
		}
	}


}

int main() {

	cin >> n;

	nQueen_DFS(1);

	cout << ans;

	return 0;
}
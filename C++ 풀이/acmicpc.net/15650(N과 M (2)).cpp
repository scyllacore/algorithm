#include <iostream>

using namespace std;

int n, m;
int arr[9] = { 0 };

void DFS(int start,int depth) {

	int i;

	if (depth > m) {

		for (i = 1; i <= m; i++) {
			cout << arr[i] << ' ';
		}
		cout << '\n';

		return;
	}

	for (i = start; i <= n; i++) {
		arr[depth] = i;
		DFS(i + 1, depth + 1);
	}


}

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);


	cin >> n >> m;

	DFS(1,1);


}
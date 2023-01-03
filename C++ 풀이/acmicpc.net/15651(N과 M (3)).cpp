#include <iostream>

using namespace std;

int n, m;
int arr[8];

void DFS(int depth) {
	
	int i;

	if (depth > m) {
		for (i = 1; i <= m; i++) {
			cout << arr[i] << ' ';
		}
		cout << '\n';
		return;
	}

	for (i = 1; i <= n; i++) {
		arr[depth] = i;
		DFS(depth + 1);
	}


}


int main() {
	
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> n >> m;

	DFS(1);

}
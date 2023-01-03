#include <iostream>
#include <algorithm>

using namespace std;

int n, m;
int arr[10] = {0};
int sequence[9] = {0};

void DFS(int start, int depth) {

	int i;

	if (depth > m) {

		for (i = 1; i <= m; i++) {
			cout << sequence[i] << ' ';
		}
		cout << '\n';
		return;
	}

	for (i = start; i <= n; i++) {
		sequence[depth] = arr[i];
		DFS(i + 1, depth + 1);
	}


}

int main() {

	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> n >> m;

	int i;

	for (i = 1; i <= n; i++) {
		cin >> arr[i];
	}

	sort(arr, arr + (n + 1));

	DFS(1, 1);

	return 0;
}

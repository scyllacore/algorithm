#include <iostream>
#include <algorithm>

using namespace std;

int n, m;
int arr[9] = { 0 };
int sequence[9] = { 0 };
bool check[9] = { 0 };


void DFS_btrk(int depth) {

	int i;

	if (depth > m) {

		for (i = 1; i <= m; i++) {
			cout << sequence[i] << ' ';
		}
		cout << '\n';
		return;
	}

	for (i = 1; i <= n; i++) {

		if (check[i]) continue;

		sequence[depth] = arr[i];
		check[i] = true;
		DFS_btrk(depth + 1);
		check[i] = false;

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
	sort(arr+1, arr + (n + 1));

	DFS_btrk(1);

	return 0;

}
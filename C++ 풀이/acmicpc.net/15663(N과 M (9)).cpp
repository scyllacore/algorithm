#include <iostream>
#include <algorithm>

using namespace std;

int arr[10] = { 0 };
int sequence[10] = { 0 };
int check[10] = { 0 };

int n, m;

void DFS_btrk(int depth) {
	int i;

	if (depth > m) {
		for (i = 1; i <= m; i++) {
			cout << sequence[i] << ' ';
		}
		cout << '\n';
		return;
	}


	int preNum = 0;

	for (i = 1; i <= n; i++) {

		if (check[i] || arr[i] == preNum) continue;

		preNum = sequence[depth] = arr[i];
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
	sort(arr + 1, arr + (n + 1));

	DFS_btrk(1);

	return 0;

}
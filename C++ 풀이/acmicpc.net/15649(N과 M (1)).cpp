#include <iostream>

using namespace std;

int arr[9]={0};
bool check[9]={0};

int n, m;

void DFS_btrk(int depth) {

	int i;

	if (depth > m) {

		for(i=1; i<=m; i++)
		{
			cout << arr[i] << ' ';
		}
		cout << '\n';

		return;

	}


	for (i = 1; i <= n; i++) {
		if (check[i]) continue;

		arr[depth] = i;
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

	DFS_btrk(1);

}
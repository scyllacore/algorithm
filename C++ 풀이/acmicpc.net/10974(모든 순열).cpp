#include <iostream>

using namespace std;

int sequence[9];
bool check[9]={0};

int n;

void DFS_btrk(int depth) {

	int i;

	if (depth > n) {

		for (i = 1; i <= n; i++) {
			cout << sequence[i] << ' ';
		}
		cout << '\n';
		return;
	}

	for (i = 1; i <= n; i++) {

		if (check[i]) continue;
		
		sequence[depth] = i;
		check[i] = true;
		DFS_btrk(depth + 1);
		check[i] = false;
	}


}

int main() {

	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> n;

	DFS_btrk(1);

}
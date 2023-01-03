#include <iostream>

using namespace std;

int lotto[14];
int sequence[7];
//bool check[14];

int n;

void DFS_btrk(int start, int depth) {

	int i;

	if (depth > 6) {
		for (i = 1; i <= 6; i++) {
			cout << sequence[i] << ' ';
		}
		cout << '\n';
		return;
	}

	for(i=start; i<=n; i++){
		sequence[depth] = lotto[i];
		DFS_btrk(i + 1, depth + 1);
	}

}

int main() {

	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	int i;

	while (1) {

		cin >> n;

		if (n == 0) { break; }

		for (i = 1; i <= n; i++) {
			cin >> lotto[i];
		}

		DFS_btrk(1, 1);
		cout << '\n';
	}

	return 0;
	
}
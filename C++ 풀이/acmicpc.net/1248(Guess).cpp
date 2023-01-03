#include <iostream>

using namespace std;

int n;
char map[11][11] = { {0} };
int sequence[11] = { 0 };

bool checkState(int depth) {

	int i;
	int sum = 0;

	for (i = depth; i >= 1; i--) {

		sum += sequence[i];

		if ((sum < 0) && (map[i][depth] != '-')) return 0;
		if ((sum > 0) && (map[i][depth] != '+')) return 0;
		if ((sum == 0) && (map[i][depth] != '0')) return 0;

	}

	return 1;

}


void DFS_btrk(int depth) {

	int i;

	if (depth > n) {

		for (i = 1; i <= n; i++) {
			cout << sequence[i] << ' ';
		}
		exit(0);
	}

	/*
	for (i = 1; i <= depth; i++) {
		cout << sequence[i] << ' ';
	}
	cout << '\n';
	*/

	for (i = -10; i <= 10; i++) {

		sequence[depth] = i;

		if (checkState(depth)) {
			DFS_btrk(depth + 1);

		}

	}


}

int main() {
	cin.tie(NULL);

	cout.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> n;

	string str;
	cin >> str;

	int i, j, cnt = 0;

	for (i = 1; i <= n; i++) {
		for (j = i; j <= n; j++) {
			map[i][j] = str[cnt++];
		}
	}


	/*
		for (i = 1; i <= n; i++) {
		for (j = 1; j <= n; j++) {
			if (map[i][j] == 0) {
				cout << "  ";
			}
			else {
				cout << map[i][j] << ' ';
			}
		}
		cout << '\n';
	}	
	*/


	DFS_btrk(1);

}

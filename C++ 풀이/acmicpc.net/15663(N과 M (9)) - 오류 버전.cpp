#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

vector<int> arr;
int sequence[9] = { 0 };
int check[10] = { 0 };

int n, m;

void DFS_btrk(int depth) {

	int i;

	if (depth >= m) {
		for (i = 0; i < m; i++) {
			cout << sequence[i] << ' ';
		}
		cout << '\n';
		return;
	}

	for (i = 0; i < arr.size(); i++) {

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

	int i, num;

	for (i = 0; i < n; i++) {
		cin >> num;
		arr.push_back(num);
	}

	sort(arr.begin(), arr.end());
	arr.erase(unique(arr.begin(), arr.end()), arr.end());

	DFS_btrk(0);

	return 0;

}
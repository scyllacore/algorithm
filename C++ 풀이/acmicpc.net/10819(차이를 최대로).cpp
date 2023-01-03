#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

int arr[9] = { 0 };
int sequence[9] = { 0 };
bool check[9] = { 0 };

int n;
int maxVal = -999;

void DFS_btrk(int depth) {
	
	int i;

	if (depth > n) {
	
		int sum = 0;

		for (i = 2; i <= n; i++) {
			sum += abs(sequence[i - 1] - sequence[i]);
		}
		maxVal = max(sum, maxVal);
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

	cin >> n;

	int i;
	for (i = 1; i <= n; i++) {
		cin >> arr[i];
	}

	DFS_btrk(1);
	
	cout << maxVal;

	return 0;
}

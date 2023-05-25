#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

bool visited[8] = { 0 };
vector<int> arr;
vector<int> sequence;

int n;
int maxVal = -9999;

void dfs(int depth) {
	if (depth >= n) {
		int sum = 0;

		for (int i = 1; i < n; i++) {
			sum += abs(sequence[i - 1] - sequence[i]);
		}

		maxVal = max(sum, maxVal);
		return;
	}

	for (int i = 0; i < n; i++) {
		if (visited[i]) {
			continue;
		}

		visited[i] = 1;
		sequence.push_back(arr[i]);

		dfs(depth + 1);
		visited[i] = 0;
		sequence.pop_back();
	}


}

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> n;

	arr.assign(n, 0);

	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	dfs(0);

	cout << maxVal;
	return 0;
}
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	int n, k;

	cin >> n >> k;

	vector<int> child(n);

	for (int i = 0; i < n; i++) {
		cin >> child[i];
	}

	vector<int> cost(n - 1);

	for (int i = 0; i < n - 1; i++) {
		cost[i] = child[i + 1] - child[i];
	}

	sort(cost.begin(), cost.end());

	int ans = child[n - 1] - child[0];

	for (int i = n - 2; i > n - k - 1; i--) {
		ans -= cost[i];
	}

	cout << ans;

	return 0;
}

//https://leesh111112.tistory.com/381
#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

int n, m;
vector<int> card;

int ans = (int)1e9;

void dfs(int start, int depth, int sum) {
	if (depth > 3) {
		if (sum <= m && abs(sum - m) < abs(ans - m)) {
			ans = sum;
		}
		return;
	}

	for (int i = start; i < n; i++) {
		dfs(i + 1, depth + 1, sum + card[i]);
	}

}

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> n >> m;

	card.assign(n, 0);

	for (int i = 0; i < n; i++) {
		cin >> card[i];
	}

	dfs(0, 1, 0);

	cout << ans;
	return 0;
}
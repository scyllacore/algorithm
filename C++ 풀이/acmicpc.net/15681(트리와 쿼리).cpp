#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

#define SIZE (int)1e5

vector<vector<int>> tree;
int dp[SIZE + 1] = { 0 };

int dfs(int root) {

	if (dp[root] != 0) {
		return dp[root];
	}

	dp[root] = 1;

	for (int i = 0; i < tree[root].size(); i++) {
		int nextRoot = tree[root][i];

		if (!dp[nextRoot]) {
			dp[root] += dfs(nextRoot);
		}
	}

	return dp[root];
}

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	int n, r, q;
	cin >> n >> r >> q;

	tree.assign(n + 1, vector<int>(0));

	int a, b;
	for (int i = 0; i < n - 1; i++) {
		cin >> a >> b;
		tree[a].push_back(b);
		tree[b].push_back(a);
	}

	dfs(r);

	int qIn;

	for (int i = 0; i < q; i++) {
		cin >> qIn;
		cout << dp[qIn] << '\n';
	}

	return 0;
}

/*
int dfs(int root,int parent) {

	if (dp[root] != 0) {
		return dp[root];
	}

	dp[root] = 1;

	for (int i = 0; i < tree[root].size(); i++) {
		int nextRoot = tree[root][i];

		if (nextRoot != parent) {
			dp[root] += dfs(nextRoot,root);
		}
	}

	return dp[root];
}
*/
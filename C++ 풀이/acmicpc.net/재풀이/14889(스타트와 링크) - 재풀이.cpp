#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

bool visited[20] = { 0 };
vector<vector<int>> stats;
int n;

int ans = (int)1e6;

void dfs(int start, int depth) {
	if (depth >= n / 2) {
		int teamS = 0;
		int teamL = 0;

		for (int i = 0; i < n - 1; i++) {
			for (int j = i + 1; j < n; j++) {
				if (visited[i] && visited[j]) {
					teamS += stats[i][j] + stats[j][i];
				}
				else if (!visited[i] && !visited[j]) {
					teamL += stats[i][j] + stats[j][i];

				}
			}
		}

		ans = min(abs(teamS - teamL), ans);
		return;
	}

	for (int i = start; i < n; i++) {
		visited[i] = 1;
		dfs(i + 1, depth + 1);
		visited[i] = 0;
	}
}

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> n;

	stats.assign(n, vector<int>(n, 0));

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> stats[i][j];
		}
	}

	dfs(0, 0);

	cout << ans;
	return 0;
}
#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int n;
int stats[20][20];
bool visited[20];

int ans = (int)1e5;

void dfs(int start, int depth) {

	if (depth >= n) {

		int teamS = 0, teamL = 0;

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

		ans = min(abs(teamL - teamS), ans);
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

	int i, j;

	for (i = 0; i < n; i++) {
		for (j = 0; j < n; j++) {
			cin >> stats[i][j];
		}
	}

	for (i = 0; i < n; i++) {
		dfs(0, i);
	}

	cout << ans;

	return 0;
}
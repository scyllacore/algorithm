#include <iostream>
#include <algorithm>

using namespace std;

int W[11][11];
int sequence[11];
bool visited[11];
int n;

int answer = (int)1e7;

void dfs(int depth, int costSum) {

	if (costSum > answer) {
		return;
	}

	int cost;

	if (depth > n) {
		cost = W[sequence[n]][sequence[1]];
		if (cost == 0) {
			return;
		}

		answer = min(cost + costSum, answer);
		return;
	}


	for (int i = 1; i <= n; i++) {
		if (visited[i]) {
			continue;
		}

		visited[i] = 1;
		sequence[depth] = i;

		cost = W[sequence[depth - 1]][sequence[depth]];
		if (cost > 0) {
			dfs(depth + 1, cost + costSum);
		}

		visited[i] = 0;

		/*
		if (cost == 0) {
			visited[i] = 0;
			continue;
		}
		dfs(depth + 1, cost + costSum);

		visited[i] = 0;
		*/

	}

}

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> n;

	int i, j;

	for (i = 1; i <= n; i++) {
		for (j = 1; j <= n; j++) {
			cin >> W[i][j];
		}
	}

	for (i = 1; i <= n; i++) {
		visited[i] = 1;

		sequence[1] = i;
		dfs(2, 0);

		visited[i] = 0;
	}

	cout << answer;

	return 0;


}
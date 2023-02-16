#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

vector<vector<int>> subway;
int visited[3001];
int startStation;

queue<int> bfsQ;

bool dfs(int curStation, int preStation) {

	visited[curStation] = 1;

	for (int i = 0; i < subway[curStation].size(); i++) {
		int nextStation = subway[curStation][i];

		if (nextStation == preStation) {
			continue;
		}

		if (nextStation == startStation) {
			return 1;
		}

		if (visited[nextStation]) {
			continue;
		}

		if (dfs(nextStation, curStation)) {
			return 1;
		}

	}

	visited[curStation] = 0;
	return 0;
}

void bfs() {

	for (; !bfsQ.empty();) {
		int curStation = bfsQ.front();
		bfsQ.pop();

		for (int i = 0; i < subway[curStation].size(); i++) {

			int nextStation = subway[curStation][i];

			if (!visited[nextStation]) {
				visited[nextStation] = visited[curStation] + 1;
				bfsQ.push(nextStation);
			}

		}
	}
}

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	int n;
	cin >> n;

	subway.assign(n + 1, vector<int>(0));

	int i, a, b;

	for (i = 0; i < n; i++) {
		cin >> a >> b;
		subway[a].push_back(b);
		subway[b].push_back(a);
	}

	for (i = 1; i <= n; i++) {
		startStation = i;
		if (dfs(i, 0)) {
			break;
		}
	}

	for (i = 1; i <= n; i++) {
		if (visited[i]) {
			bfsQ.push(i);
		}
	}

	bfs();

	for (i = 1; i <= n; i++) {
		cout << visited[i] - 1 << ' ';
	}

	return 0;
}
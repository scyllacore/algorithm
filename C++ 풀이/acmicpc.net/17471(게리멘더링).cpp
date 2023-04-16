#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <cmath>

using namespace std;

#define MAX_SIZE 10
#define MAX (int)1e6

int n;
int countOfArea[MAX_SIZE + 1];
vector<vector<int>> graph;
bool visited[MAX_SIZE + 1] = { 0 };
bool areaTeam[MAX_SIZE + 1] = { 0 };

int ans = MAX;

void bfs(int start) {

	queue<int> bfsQ;
	bfsQ.push(start);
	visited[start] = 1;

	for (; !bfsQ.empty();) {

		int cur = bfsQ.front();
		bfsQ.pop();

		for (int i = 0; i < graph[cur].size(); i++) {
			int next = graph[cur][i];

			if (!visited[next] && areaTeam[next] == areaTeam[start]) {
				visited[next] = 1;
				bfsQ.push(next);
			}
		}
	}

}

bool isTrueArea() {

	fill_n(visited, MAX_SIZE + 1, 0);

	int areaN = 0;

	for (int i = 1; i <= n; i++) {
		if (!visited[i]) {
			bfs(i);
			areaN++;
		}
	}

	if (areaN == 2) {
		return 1;
	}

	return 0;
}

int calDiff() {

	int teamA = 0;
	int teamB = 0;

	for (int i = 1; i <= n; i++) {
		if (areaTeam[i]) {
			teamA += countOfArea[i];
		}
		else {
			teamB += countOfArea[i];
		}
	}

	return abs(teamA - teamB);
}

void dfs(int depth) {

	if (depth >= n) {

		bool res = isTrueArea();

		if (res) {
			ans = min(calDiff(), ans);
		}

		return;
	}

	areaTeam[depth + 1] = 0;
	dfs(depth + 1);

	areaTeam[depth + 1] = 1;
	dfs(depth + 1);
}

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> n;

	graph.assign(n + 1, vector<int>(0));

	for (int i = 1; i <= n; i++) {
		cin >> countOfArea[i];
	}

	int a, b;
	int size, next;

	for (int i = 1; i <= n; i++) {
		cin >> size;

		for (int j = 0; j < size; j++) {
			cin >> next;
			graph[i].push_back(next);
			graph[next].push_back(i);
		}
	}

	dfs(0);

	if (ans == MAX) {
		cout << -1;
	}
	else {
		cout << ans;
	}

	return 0;
}
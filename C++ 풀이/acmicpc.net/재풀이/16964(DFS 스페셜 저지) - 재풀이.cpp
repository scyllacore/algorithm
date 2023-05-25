#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

#define MAX (int)1e5

int n;
vector<vector<int>> graph;

int originVisitedOrder[MAX + 1] = { 0 };
int newVisitedOrder[MAX + 1] = { 0 };

int order = 1;

bool cmp(const int& idx1, const int& idx2) {
	return originVisitedOrder[idx1] < originVisitedOrder[idx2];
}

void dfs(int cur) {

	newVisitedOrder[cur] = order++;

	for (int i = 0; i < graph[cur].size(); i++) {
		int next = graph[cur][i];

		if (!newVisitedOrder[next]) {
			dfs(next);
		}
	}
}

bool isTrueDfs() {
	for (int i = 1; i <= n; i++) {
		if (originVisitedOrder[i] != newVisitedOrder[i]) {
			return 0;
		}
	}
	return 1;
}


int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> n;

	graph.assign(n + 1, vector<int>(0));

	int i, a, b;

	for (i = 0; i < n - 1; i++) {
		cin >> a >> b;

		graph[a].push_back(b);
		graph[b].push_back(a);
	}


	for (i = 1; i <= n; i++) {
		cin >> a;
		originVisitedOrder[a] = i;
	}

	for (i = 1; i <= n; i++) {
		sort(graph[i].begin(), graph[i].end(), cmp);
	}

	dfs(1);

	cout << isTrueDfs();

	return 0;
}
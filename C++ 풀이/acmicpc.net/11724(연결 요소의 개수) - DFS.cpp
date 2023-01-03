#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int n, m;
vector<vector<int>> graph;
bool visited[1001] = { 0 };

void DFS_btrk(int nodeN) {

	int i;

	for (i = 0; i < graph[nodeN].size(); i++) {

		if (visited[graph[nodeN][i]]) continue;

		visited[graph[nodeN][i]] = 1;
		DFS_btrk(graph[nodeN][i]);
	}

}

int main() {

	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> n >> m;

	graph.assign(n + 1, vector<int>(0));

	int i, cnt = 0;
	int node1, node2;

	for (i = 1; i <= m; i++) {
		cin >> node1 >> node2;
		graph[node1].push_back(node2);
		graph[node2].push_back(node1);
	}

	for (i = 1; i <= n; i++) {
		sort(graph[i].begin(), graph[i].end());
	}

	for(i=1; i<=n; i++){
		if (visited[i]) continue;

		visited[i] = 1;
		DFS_btrk(i);
		cnt++;
	}

	cout << cnt;

	return 0;

}
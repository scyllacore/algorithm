#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

vector<int> graph[1001];
queue<int> qBFS;
int n, m, v;
bool visited[1001] = { 0 };

void DFS_btrk(int nodeN) {

	cout << nodeN << ' ';

	/*
	if (graph[nodeN].empty()) {
		return;
	} 비어있다면 연결되지 않은 것이다.*/

	int i;

	for (i = 0; i < graph[nodeN].size(); i++) {

		if (visited[graph[nodeN][i]]) continue;

		visited[graph[nodeN][i]] = 1;
		DFS_btrk(graph[nodeN][i]);
	}


}

void BFS_btrk(int nodeN) {

	int i;

	while (!qBFS.empty()) {
		nodeN = qBFS.front();
		qBFS.pop();

		for (i = 0; i < graph[nodeN].size(); i++) {
			if (visited[graph[nodeN][i]]) continue;

			visited[graph[nodeN][i]] = 1;
			qBFS.push(graph[nodeN][i]);
			cout << graph[nodeN][i] << ' ';
		}
	}

}

int main() {

	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> n >> m >> v;

	int i, node1, node2;

	for (i = 1; i <= m; i++) {
		cin >> node1 >> node2;
		graph[node1].push_back(node2);
		graph[node2].push_back(node1);

	}

	for (i = 1; i <= n; i++) {
		sort(graph[i].begin(), graph[i].end());
		graph[i].erase(unique(graph[i].begin(), graph[i].end()), graph[i].end());
	}

	visited[v] = 1;
	DFS_btrk(v);

	fill_n(visited, n + 1, 0);
	cout << '\n';

	qBFS.push(v);
	visited[v] = 1;
	cout << v << ' ';
	BFS_btrk(v);

	return 0;

}

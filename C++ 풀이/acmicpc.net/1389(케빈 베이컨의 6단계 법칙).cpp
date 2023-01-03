#include <iostream>
#include <vector>
#include <queue>
#include <climits>

using namespace std;

vector<vector<int>> graph;
queue<pair<int, int>> bfsNode;

bool visited[101] = { 0 };

int BFS() {

	int i;
	int node,bacon,nextNode;
	int sumBacon = 0;

	while (!bfsNode.empty()) {
		
		node = bfsNode.front().first;
		bacon = bfsNode.front().second;
		sumBacon += bacon;
		bfsNode.pop();

		for (i = 0; i < graph[node].size(); i++) {

			nextNode = graph[node][i];

			if (!visited[nextNode]) {
				visited[nextNode] = 1;
				bfsNode.push(make_pair(nextNode, bacon + 1));
			}

		}

	}

	return sumBacon;

}

int main() {

	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	int n, m;

	cin >> n >> m;

	graph.assign(n + 1, vector<int>(0));

	int i,j,tmp, parent, child;
	int ansBacon = INT_MAX, ansNode=0;

	for (i = 1; i <= m; i++) {

		cin >> parent >> child;

		graph[parent].push_back(child);
		graph[child].push_back(parent);
	}

	for (i = 1; i <= n; i++) {

		visited[i] = 1;
		bfsNode.push(make_pair(i, 0));
		tmp = BFS();

		if (tmp < ansBacon) {
			ansBacon = tmp;
			ansNode = i;
		}

		fill_n(visited, 101, 0);

	}

	cout << ansNode;

	return 0;

}

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct treeNode {
	int node;
	int dist;
};

int n, maxNode = 0, maxDist = 0;
vector<vector<treeNode>> graph;
bool visited[10001] = { 0 };

void DFS(int parent, int sumDist) {

	if (sumDist > maxDist) {
		maxDist = sumDist;
		maxNode = parent;
	}

	int child, dist, i;

	for (i = 0; i < graph[parent].size(); i++) {

		child = graph[parent][i].node;
		dist = graph[parent][i].dist;

		if (!visited[child]) {
			visited[child] = 1;
			DFS(child, sumDist + dist);
		}

	}

}


int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> n;

	graph.assign(n + 1, vector<treeNode>(0));

	int i, parent, child, dist;

	for (i = 1; i <= n - 1; i++) {
		cin >> parent >> child >> dist;

		graph[child].push_back({ parent,dist });
		graph[parent].push_back({ child,dist });
	}

	visited[1] = 1;
	DFS(1, 0);
	fill_n(visited, 10001, 0);

	maxDist = 0;

	visited[maxNode] = 1;
	DFS(maxNode, 0);

	cout << maxDist;

	return 0;

}
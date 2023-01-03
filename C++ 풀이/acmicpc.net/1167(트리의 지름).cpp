#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

struct treeNode {
	int node;
	int distance;
};

int v, maxDis = 0, maxNode = 0;
int ans = 0;
vector<vector<treeNode>> graph;
bool visited[100001] = { 0 };

void DFS(int parent, int disSum) {

	int i, child, dis;

	if (disSum > maxDis) {
		maxDis = disSum;
		maxNode = parent;
	}

	for (i = 0; i < graph[parent].size(); i++) {

		child = graph[parent][i].node;
		dis = graph[parent][i].distance;

		if (!visited[child]) {
			visited[child] = 1;
			DFS(child, dis + disSum);
		}

	}

}


int main() {

	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> v;

	graph.assign(v + 1, vector<treeNode>(0));

	int i, parent, child, distance;

	for (i = 1; i <= v; i++) {
		cin >> parent;

		for (;;) {
			cin >> child;
			if (child == -1) {
				break;
			}
			cin >> distance;
			graph[parent].push_back({ child,distance });
			graph[child].push_back({ parent,distance });
		}
	}

	visited[1] = 1;
	DFS(1, 0);

	fill_n(visited, 100001, 0);
	maxDis = 0;

	visited[maxNode] = 1;
	DFS(maxNode, 0);

	cout << maxDis;

	return 0;

}

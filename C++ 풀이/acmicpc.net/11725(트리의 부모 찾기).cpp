#include <iostream>
#include <vector>
using namespace std;

int n;
bool visited[100001] = { 0 };
int parentNode[100001] = { 0 };

vector<vector<int>> graph;

void DFS(int parent) {

	int i, child;

	for (i = 0; i < graph[parent].size(); i++) {

		child = graph[parent][i];

		if (!visited[child]) {
			visited[child] = 1;
			parentNode[child] = parent;
			DFS(child);
		}

	}


}

int main() {

	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> n;

	graph.assign(n + 1, vector<int>(0));

	int i, node1, node2;

	for (i = 1; i <= n - 1; i++) {
		cin >> node1 >> node2;

		graph[node1].push_back(node2);
		graph[node2].push_back(node1);
	}

	visited[1] = 1;
	DFS(1);

	for (i = 2; i <= n; i++) {
		cout << parentNode[i] << '\n';
	}

}

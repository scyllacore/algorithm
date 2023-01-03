#include <iostream>
#include <vector>
#include <queue>

using namespace std;

bool visited[1001] = { 0 };

vector<vector<int>> graph;

void BFS(int node) {

	queue<int> bfsQ;

	visited[node] = 1;
	bfsQ.push(node);

	int curNode,nextNode;
	int i,size;

	while (!bfsQ.empty()) {
		
		curNode = bfsQ.front();
		size = graph[curNode].size();
		bfsQ.pop();

		for (i = 0; i < size; i++) {
			nextNode = graph[curNode][i];

			if (!visited[nextNode]) {
				visited[nextNode] = 1;
				bfsQ.push(nextNode);
			}
		}

	}


}

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	int n, m;

	cin >> n >> m;

	int i;
	int a, b;

	graph.assign(n + 1, vector<int>(0));

	for (i = 0; i < m; i++) {
		cin >> a >> b;
		graph[a].push_back(b);
		graph[b].push_back(a);
	}

	int ans = 0;

	for (i = 1; i <= n; i++) {
		if (!visited[i]) {
			BFS(i);
			ans++;
		}
	}

	cout << ans;

}


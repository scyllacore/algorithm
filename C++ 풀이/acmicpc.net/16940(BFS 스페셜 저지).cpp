#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

vector<vector<int>> graph;
queue<int> nodeBFS;
vector<int> nodeOrder, inOrder, ansOrder(1,0);
bool visited[100001] = { 0 };

int n;

bool compare(const int& idx1, const int& idx2) {

	return nodeOrder[idx1] < nodeOrder[idx2];
}

void BFS() {

	int i, nodeN, nextNode;

	while (!nodeBFS.empty()) {

		nodeN = nodeBFS.front();
		nodeBFS.pop();

		for (i = 0; i < graph[nodeN].size(); i++) {

			nextNode = graph[nodeN][i];

			if (visited[nextNode]) continue;

			visited[nextNode] = 1;
			nodeBFS.push(nextNode);
			ansOrder.push_back(nextNode);
		}
	}
}

bool isBFS() {
	int i;	

	for (i = 1; i < inOrder.size(); i++) {
		if (inOrder[i] != ansOrder[i])
			return 0;
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

	for (i = 1; i <= n - 1; i++) {
		cin >> a >> b;
		graph[a].push_back(b);
		graph[b].push_back(a);
	}

	nodeOrder.assign(n + 1, 0);
	inOrder.assign(n+1, 0);

	for (i = 1; i <= n; i++) {
		cin >> inOrder[i];
		nodeOrder[inOrder[i]] = i;
	}

	for (i = 1; i <= n; i++) {
		sort(graph[i].begin(), graph[i].end(), compare);
	}

	nodeBFS.push(1);
	ansOrder.push_back(1);
	visited[1] = 1;

	BFS();

	cout << isBFS();

}
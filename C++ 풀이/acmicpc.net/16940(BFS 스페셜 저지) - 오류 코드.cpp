#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

vector<vector<int>> graph;
queue<int> nodeBFS;
vector<int> nodeOrder, inOrder;
int visited[100001] = { 0 };

int n;

bool BFS() {
	nodeBFS.push(1);
	visited[1] = 1;

	int i, nodeN, nextNode;
	int cnt = 1;

	while (!nodeBFS.empty()) {

		nodeN = nodeBFS.front();
		nodeBFS.pop();

		for (i = 0; i < graph[nodeN].size(); i++) {

			nextNode = graph[nodeN][i];

			if (visited[nextNode]) continue;

			if (visited[nextNode] < cnt) {
				continue;
			}

			if (nodeOrder[nextNode] != cnt + 1) {
				return 0;
			}

			visited[nextNode] = ++cnt;
			nodeBFS.push(nextNode);

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

	for (i = 1; i <= n - 1; i++) {
		cin >> a >> b;
		graph[a].push_back(b);
		graph[b].push_back(a);
	}

	nodeOrder.assign(n + 1, 0);
	inOrder.assign(n + 1, 0);

	for (i = 1; i <= n; i++) {
		cin >> inOrder[i];
		nodeOrder[inOrder[i]] = i;
	}

	cout << BFS();
}
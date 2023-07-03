#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

#define INF (int)1e9

struct node {
	int n;
	int d;
};

struct cmp {
	bool operator()(const node n1, const node n2) {
		return n1.d > n2.d;
	}
};

vector<int> dis;
vector<vector<node>> graph;

void bfs(int start) {
	priority_queue<node, vector<node>, cmp> nodePQ;

	dis[start] = 0;
	nodePQ.push({ start,0 });

	for (; !nodePQ.empty();) {

		int curU = nodePQ.top().n;
		int curW = nodePQ.top().d;
		nodePQ.pop();

		for (int i = 0; i < graph[curU].size(); i++) {
			node nextNode = graph[curU][i];
			int v = nextNode.n;
			int w = nextNode.d;

			if (curW + w < dis[v]) {
				dis[v] = curW + w;
				nodePQ.push({ v,curW + w });
			}
		}
	}

}

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	int V, E;
	cin >> V >> E;

	dis.assign(V + 1, INF);
	graph.assign(V + 1, vector<node>(0));

	int K;
	cin >> K;

	int u, v, w;

	for (int i = 0; i < E; i++) {
		cin >> u >> v >> w;
		graph[u].push_back({ v,w });
	}

	bfs(K);

	for (int i = 1; i <= V; i++) {
		if (dis[i] == INF) {
			cout << "INF";
		}
		else {
			cout << dis[i];
		}
		cout << '\n';
	}

	return 0;
}
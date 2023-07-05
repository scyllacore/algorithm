#include <iostream>
#include <vector>
#include <queue>
#include <string>

using namespace std;

#define INF (int)1e9
#define SIZE (int)2e4

struct node {
	int u;
	int w;
};

struct cmp {
	bool operator()(const node& n1, const node& n2) {
		return n1.w > n2.w;
	}
};

int shortDis[SIZE + 1];

void dijkstra(int start, vector<vector<node>>& graph) {
	priority_queue<node, vector<node>, cmp> nodePQ;

	nodePQ.push({ start,0 });
	shortDis[start] = 0;

	for (; !nodePQ.empty();) {
		int curU = nodePQ.top().u;
		int curW = nodePQ.top().w;
		nodePQ.pop();

		for (int i = 0; i < graph[curU].size(); i++) {
			int nextV = graph[curU][i].u;
			int nextW = graph[curU][i].w;

			if (curW + nextW < shortDis[nextV]) {
				shortDis[nextV] = curW + nextW;
				nodePQ.push({ nextV,curW + nextW });
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

	int K;
	cin >> K;

	vector<vector<node>> graph(V + 1);

	int u, v, w;
	for (int i = 0; i < E; i++) {
		cin >> u >> v >> w;
		graph[u].push_back({ v,w });
	}

	fill(&shortDis[0], &shortDis[SIZE + 1], INF);
	dijkstra(K, graph);

	for (int i = 1; i <= V; i++) {
		cout << (shortDis[i] == INF ? "INF" : to_string(shortDis[i])) << '\n';
	}

	return 0;
}
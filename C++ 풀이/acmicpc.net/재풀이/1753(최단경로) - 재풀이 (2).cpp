#include <iostream>
#include <vector>
#include <queue>

using namespace std;

#define SIZE (int)2e4
#define INF (int)1e9

struct node {
	int v;
	int w;
};

struct cmp {
	bool operator()(const node& n1, const node& n2) {
		return n1.w > n2.w;
	}
};

int shortestW[SIZE + 1];

void dijkstra(vector<vector<node>>& graph, int start) {

	priority_queue<node, vector<node>, cmp> nodePQ;
	shortestW[start] = 0;
	nodePQ.push({ start,0 });

	for (; !nodePQ.empty();) {
		int curU = nodePQ.top().v;
		int curW = shortestW[curU]; //nodePQ.top().w;
		nodePQ.pop();

		for (int i = 0; i < graph[curU].size(); i++) {
			int nextV = graph[curU][i].v;
			int nextW = graph[curU][i].w;

			if (curW + nextW < shortestW[nextV]) {
				shortestW[nextV] = curW + nextW;
				nodePQ.push({ nextV,curW + nextW });
			}
		}

	}


}

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	fill(&shortestW[0], &shortestW[SIZE + 1], INF);

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

	dijkstra(graph, K);

	for (int i = 1; i <= V; i++) {
		if (shortestW[i] == INF) {
			cout << "INF";
		}
		else {
			cout << shortestW[i];

		}
		cout << '\n';
	}
}
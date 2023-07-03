#include <iostream>
#include <queue>
#include <vector>

using namespace std;

#define INF (int)1e9
#define SIZE (int)2e4

struct node {
	int v;
	int w;
};

struct cmp {
	bool operator()(const node& n1, const node& n2) {
		return n1.w > n2.w;
	}
};

int dis[SIZE + 1];

vector<vector<node>> graph;

void dijkstra(int root) {
	priority_queue<node, vector<node>, cmp> pq;

	dis[root] = 0;
	pq.push({ root,0 });

	for (; !pq.empty();) {
		int curU = pq.top().v;
		int curW = pq.top().w;
		pq.pop();

		for (int i = 0; i < graph[curU].size(); i++) {
			int nextV = graph[curU][i].v;
			int nextW = graph[curU][i].w;

			if (curW + nextW < dis[nextV]) {
				dis[nextV] = curW + nextW;
				pq.push({ nextV,curW + nextW });
			}
		}
	}

}

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	fill(&dis[0], &dis[SIZE + 1], INF);

	int V, E;
	cin >> V >> E;

	graph.assign(V + 1, vector<node>(0));

	int K;
	cin >> K;

	int u, v, w;
	for (int i = 0; i < E; i++) {
		cin >> u >> v >> w;
		graph[u].push_back({ v,w });
	}

	dijkstra(K);

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
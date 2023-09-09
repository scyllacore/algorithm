#include <iostream>
#include <vector>
#include <queue>

using namespace std;

#define SIZE (int)5e4
#define INF (int)1e9

struct node {
	int u;
	int w;
};

struct cmp {
	bool operator()(const node& n1, const node& n2) {
		return n1.w > n2.w;
	}
};

int weight[SIZE + 1] = { 0 };

void dijkstra(vector<vector<node>>& graph, int start) {

	fill(&weight[0], &weight[SIZE + 1], INF);

	priority_queue<node, vector<node>, cmp> pq;
	pq.push({ start,0 });
	weight[start] = 0;

	for (; !pq.empty();) {
		int curU = pq.top().u;
		int curW = pq.top().w;
		pq.pop();

		for (int i = 0; i < graph[curU].size(); i++) {
			int nextV = graph[curU][i].u;
			int connW = graph[curU][i].w;

			if (curW + connW < weight[nextV]) {
				weight[nextV] = curW + connW;
				pq.push({ nextV, weight[nextV] });
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

	vector<vector<node>> graph(n + 1);

	int u, v, w;

	for (int i = 0; i < m; i++) {
		cin >> u >> v >> w;
		graph[u].push_back({ v,w });
		graph[v].push_back({ u,w });
	}

	dijkstra(graph, 1);

	cout << weight[n];

	return 0;
}
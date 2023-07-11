#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

#define INF (int)2e9 + 1
#define SIZE 800

struct node {
	int n;
	int w;
};

struct cmp {
	bool operator()(const node& n1, const node& n2) {
		return n1.w > n2.w;
	}
};

int dis[SIZE + 1];

void dijkstra(vector<vector<node>>& graph, int start) {

	fill(&dis[0], &dis[SIZE + 1], INF);
	priority_queue<node, vector<node>, cmp> nodePQ;

	nodePQ.push({ start,0 });
	dis[start] = 0;

	for (; !nodePQ.empty();) {
		int curN = nodePQ.top().n;
		int curW = nodePQ.top().w;
		nodePQ.pop();

		for (int i = 0; i < graph[curN].size(); i++) {
			int nextN = graph[curN][i].n;
			int nextW = graph[curN][i].w;

			if (curW + nextW < dis[nextN]) {
				dis[nextN] = curW + nextW;
				nodePQ.push({ nextN,curW + nextW });
			}
		}
	}

}

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	int N, E;
	cin >> N >> E;

	vector<vector<node>> graph(N + 1);

	int a, b, c;
	for (int i = 0; i < E; i++) {
		cin >> a >> b >> c;

		graph[a].push_back({ b,c });
		graph[b].push_back({ a,c });
	}

	int v1, v2;
	cin >> v1 >> v2;

	long long v1_1, v1_v2, v1_n;

	dijkstra(graph, v1);

	v1_1 = dis[1];
	v1_v2 = dis[v2];
	v1_n = dis[N];

	long long v2_1, v2_n;

	dijkstra(graph, v2);
	v2_1 = dis[1];
	v2_n = dis[N];

	long long route1 = v1_1 + v1_v2 + v2_n;
	long long route2 = v2_1 + v1_v2 + v1_n;
	long long ans = min(route1, route2);

	if (ans >= INF) {
		ans = -1;
	}

	cout << ans;

	return 0;
}

//https://rujang.tistory.com/entry/%EB%B0%B1%EC%A4%80-1504%EB%B2%88-%ED%8A%B9%EC%A0%95%ED%95%9C-%EC%B5%9C%EB%8B%A8-%EA%B2%BD%EB%A1%9C-CC
//https://steady-coding.tistory.com/82
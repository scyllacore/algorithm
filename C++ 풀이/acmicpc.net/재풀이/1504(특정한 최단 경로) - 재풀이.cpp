#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

#define SIZE 800
#define INF (long long)2e9 + 1

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

	fill(&shortestW[0], &shortestW[SIZE + 1], INF);

	priority_queue<node, vector<node>, cmp> nodePQ;

	shortestW[start] = 0;
	nodePQ.push({ start,0 });

	for (; !nodePQ.empty();) {
		int curU = nodePQ.top().v;
		int curW = nodePQ.top().w;
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

	dijkstra(graph, v1);

	int v1_1, v1_v2, v1_n;
	v1_1 = shortestW[1];
	v1_v2 = shortestW[v2]; // v1_v2나 v2_v1이나 가중치가 똑같다. 위 입력에서 이와같이 처리한다.
	v1_n = shortestW[N];


	dijkstra(graph, v2);

	int v2_1, v2_n;
	v2_1 = shortestW[1];
	v2_n = shortestW[N];

	long long pathA = (long long)v1_1 + v1_v2 + v2_n;
	long long pathB = (long long)v2_1 + v1_v2 + v1_n;

	long long ans = min(pathA, pathB);

	if (ans >= INF) {
		cout << -1;
	}
	else {
		cout << ans;
	}

	return 0;
}
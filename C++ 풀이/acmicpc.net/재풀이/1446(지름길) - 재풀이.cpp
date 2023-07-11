#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#define SIZE (int)1e4

struct node {
	int v;
	int w;
};

int shortestW[SIZE];

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	int N, D;
	cin >> N >> D;

	vector<vector<node>> graph(SIZE + 1);

	int u, v, w;
	for (int i = 0; i < N; i++) {
		cin >> u >> v >> w;
		graph[v].push_back({ u,w });
	}

	shortestW[0] = 0;

	for (int i = 1; i <= D; i++) {
		shortestW[i] = shortestW[i - 1] + 1;

		for (int j = 0; j < graph[i].size(); j++) {
			int preU = graph[i][j].v;
			int curW = graph[i][j].w;

			shortestW[i] = min(shortestW[preU] + curW, shortestW[i]);
		}

	}

	cout << shortestW[D];

	return 0;
}
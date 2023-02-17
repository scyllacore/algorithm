#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

#define MAX (int)1e5

int n;
vector<vector<int>> graph;

int originVisitedOrder[MAX + 1] = { 0 };
int newVisitedOrder[MAX + 1] = { 0 };

bool cmp(const int& idx1, const int& idx2) {
	return originVisitedOrder[idx1] < originVisitedOrder[idx2];
}

void bfs() {
	queue<int> bfsQ;
	bfsQ.push(1);
	newVisitedOrder[1] = 1;

	int order = 2;

	for (; !bfsQ.empty();) {
		int cur = bfsQ.front();
		bfsQ.pop();

		for (int i = 0; i < graph[cur].size(); i++) {
			int next = graph[cur][i];

			if (!newVisitedOrder[next]) {
				newVisitedOrder[next] = order++; // = newVisitedOrder[cur] + 1; 최단 거리를 구하는 것이 아니다.
				bfsQ.push(next);
			}
		}

	}

}

bool isTrueBfs() {
	for (int i = 1; i <= n; i++) {
		if (originVisitedOrder[i] != newVisitedOrder[i]) {
			return 0;
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

	for (i = 0; i < n - 1; i++) {
		cin >> a >> b;

		graph[a].push_back(b);
		graph[b].push_back(a);
	}


	for (i = 1; i <= n; i++) {
		cin >> a;
		originVisitedOrder[a] = i;
	}

	for (i = 1; i <= n; i++) {
		sort(graph[i].begin(), graph[i].end(), cmp);
	}

	bfs();

	cout << isTrueBfs();

	return 0;
}
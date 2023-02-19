#include <iostream>
#include <vector>
#include <queue>

using namespace std;

#define MAX (int)1e5

int parent[MAX + 1] = { -1,-1 };
vector<vector<int>> graph;

void bfs(int start) {
	queue<int> bfsQ;
	bfsQ.push(start);

	for (; !bfsQ.empty();) {

		int cur = bfsQ.front();
		bfsQ.pop();

		for (int i = 0; i < graph[cur].size(); i++) {
			int next = graph[cur][i];

			if (!parent[next]) {
				parent[next] = cur;
				bfsQ.push(next);
			}
		}

	}


}

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	int	n;
	cin >> n;

	graph.assign(n + 1, vector<int>(0));

	int a, b;
	for (int i = 0; i < n - 1; i++) {
		cin >> a >> b;
		graph[a].push_back(b);
		graph[b].push_back(a);
	}

	bfs(1);

	for (int i = 2; i <= n; i++) {
		cout << parent[i] << '\n';
	}

	return 0;
}
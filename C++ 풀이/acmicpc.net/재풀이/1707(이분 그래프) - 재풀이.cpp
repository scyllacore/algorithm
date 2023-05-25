#include <iostream>
#include <vector>
#include <queue>

using namespace std;

#define MAX (int)2e4

int visited[MAX + 1];

vector<vector<int>> graph;

bool bfs(int start) {

	queue<int> bfsQ;

	bfsQ.push(start);
	visited[start] = 1;

	for (; !bfsQ.empty();) {
		int cur = bfsQ.front();
		bfsQ.pop();

		for (int i = 0; i < graph[cur].size(); i++) {
			int next = graph[cur][i];
			if (!visited[next]) {
				visited[next] = (visited[cur] == 1 ? 2 : 1);
				bfsQ.push(next);
			}
			else if (visited[cur] == visited[next]) {
				return false;
			}
		}
	}

	return true;

}

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	int k, v, e;
	cin >> k;

	for (; k--;) {

		cin >> v >> e;

		graph.assign(v + 1, vector<int>(0));
		fill(&visited[0], &visited[MAX + 1], 0);

		int i, a, b;

		for (i = 0; i < e; i++) {
			cin >> a >> b;
			graph[a].push_back(b);
			graph[b].push_back(a);
		}

		bool answer = 1;

		for (i = 1; i <= v; i++) {
			if (!visited[i] && !bfs(i)) {
				answer = 0;
				break;
			}
		}


		cout << (answer == 1 ? "YES" : "NO") << '\n';

	}

	return 0;

}
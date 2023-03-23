#include <iostream>
#include <queue>
#include <vector>

using namespace std;

#define MAX 100

int visited[MAX + 1] = { 0 };

int bfs(vector<vector<int>>& graph, int& a, int& b) {

	queue<int> bfsQ;
	bfsQ.push(a);
	visited[a] = 1;

	for (; !bfsQ.empty();) {

		int cur = bfsQ.front();
		bfsQ.pop();

		if (cur == b) {
			return visited[cur] - 1;
		}


		for (int i = 0; i < graph[cur].size(); i++) {
			int next = graph[cur][i];

			if (!visited[next]) {
				visited[next] = visited[cur] + 1;
				bfsQ.push(next);
			}
		}

	}

	return -1;
}

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	int n;
	cin >> n;

	vector<vector<int>> graph(n + 1, vector<int>(0));

	int a, b;
	cin >> a >> b;

	int m;
	cin >> m;

	int x, y;

	for (int i = 0; i < m; i++) {
		cin >> x >> y;
		graph[x].push_back(y);
		graph[y].push_back(x);
	}

	cout << bfs(graph, a, b);

}
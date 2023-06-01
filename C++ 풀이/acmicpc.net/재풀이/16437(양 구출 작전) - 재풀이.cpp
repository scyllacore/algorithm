#include <iostream>
#include <vector>

using namespace std;

struct nodeInfo {
	char t;
	int a;
	int p;
};

vector<nodeInfo> area;
vector<vector<int>> graph;

long long dfs(int node) {

	long long sum = area[node].t == 'S' ? area[node].a : area[node].a * -1;

	for (int i = 0; i < graph[node].size(); i++) {
		sum += dfs(graph[node][i]);
	}

	return sum > 0 ? sum : 0;
}

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	int n;
	cin >> n;

	area.assign(n + 1, { 0,0,0 });

	for (int i = 2; i <= n; i++) {
		cin >> area[i].t >> area[i].a >> area[i].p;
	}

	graph.assign(n + 1, vector<int>(0));

	for (int i = 2; i <= n; i++) {
		graph[area[i].p].push_back(i);
	}

	/*for (int i = 0; i <= n; i++) {
		for (int node : graph[i]) {
			cout << node << ' ';
		}
		cout << '\n';
	}*/

	cout << dfs(1);
	return 0;
}
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n;
vector<vector<int>> graph;
vector<int> visitedOrder;
vector<int> priority;
vector<int> result(1,0);
bool visited[100001] = { 0 };

bool compare(const int& idx1, const int& idx2) {
	return priority[idx1] < priority[idx2];
}

void DFS_btrk(int nodeN){

	int i,nextNode;

	for (i = 0; i < graph[nodeN].size(); i++) {

		nextNode = graph[nodeN][i];

		if (visited[nextNode]) continue;

		visited[nextNode] = 1;
		result.push_back(nextNode);
		DFS_btrk(nextNode);

	}


}

bool isDFS() {

	int i;


	/*for (i = 1; i <= n; i++) {
		cout << visitedOrder[i] << ' ' << result[i] << '\n';
	}*/

	for (i = 1; i <= n; i++) {
		if (visitedOrder[i] != result[i]) return 0;
	}

	return 1;

}


int main() {

	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> n;

	int i,a,b;

	graph.assign(n + 1, vector<int>(0));

	for (i = 1; i <= n-1; i++) {
		cin >> a >> b;
		graph[a].push_back(b);
		graph[b].push_back(a);
	}

	visitedOrder.assign(n + 1, 0);
	priority.assign(n + 1, 0);

	for (i = 1; i <= n; i++) {
		cin >> visitedOrder[i];
		priority[visitedOrder[i]] = i;
	}

	for (i = 1; i <= n; i++) {
		sort(graph[i].begin(), graph[i].end(), compare);
	}

	visited[1] = 1;
	result.push_back(1);
	DFS_btrk(1);

	cout << isDFS();

	return 0;

}
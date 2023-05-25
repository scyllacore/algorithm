#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#define MAX (int)1e5

struct node {
	int next, dis;
};

vector<vector<node>> graph;

int visited[MAX] = { 0 };

int startNode = 1;
int maxDis = 0;

void dfs(int cur, int disSum) {

	if (disSum > maxDis) {
		maxDis = disSum;
		startNode = cur;
	}

	for (int i = 0; i < graph[cur].size(); i++) {
		int next = graph[cur][i].next;
		int dis = graph[cur][i].dis;

		if (!visited[next]) {
			visited[next] = 1;
			dfs(next, disSum + dis);
			visited[next] = 0;
		}
	}
}



int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	int	n;
	cin >> n;

	graph.assign(n + 1, vector<node>(0));

	int cur, next, dis;
	for (int i = 0; i < n; i++) {

		cin >> cur;

		for (;;) {
			cin >> next;
			if (next == -1) {
				break;
			}
			cin >> dis;

			graph[cur].push_back({ next,dis });
		}
	}

	visited[1] = 1; //  시작할 때 방문처리를 해줘야한다.
	dfs(1, 0);//함수를 하나만 써서 해결할 수 있다.
	visited[1] = 0; // 

	maxDis = 0;
	visited[startNode] = 1; // 
	dfs(startNode, 0);

	cout << maxDis;

	return 0;
}
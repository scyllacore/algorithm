#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<vector<int>> graph;
int visited[20001] = { 0 };

bool bipartite;

void BFS(int node) {

	queue<int> bfsQ;

	visited[node] = 1;
	bfsQ.push(node);

	int curNode, nextNode;
	int i,size;

	while (!bfsQ.empty()) {

		curNode = bfsQ.front();
		size = graph[curNode].size();
		bfsQ.pop();

		for (i = 0; i < size; i++) {
			nextNode = graph[curNode][i];

			if (!visited[nextNode]) {
				bfsQ.push(nextNode);
				visited[nextNode] = (visited[curNode] == 1 ? 2 : 1); //오류1 고친 코드.
			}
			else {
				if (visited[nextNode] == visited[curNode]) {
					bipartite = 0;
					return;
				}
			}
			//오류1. state = (state == 1 ? 2 : 1); 틀린 코드 : 현재 노드 상태와 비교해야한다.
			//새로운 front값을 사용할 때 마다 구역이 바뀜으로 올바르지 않다.
		}
	
	}

}

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	int tc;
	cin >> tc;

	int v, e;
	int i;
	int a, b;

	while (tc--) {

		cin >> v >> e;
		
		graph.assign(v + 1, vector<int>(0));

		for (i = 0; i < e; i++) {
			cin >> a >> b;
			graph[a].push_back(b);
			graph[b].push_back(a);
		}

		bipartite = 1;

		//BFS(1); 오류2. 모든 노드에 대해서 확인해야한다. 1이 모든 노드와 연결되지 않다면 정확히 이분 그래프인지 따질 수 없다.

		for (i = 1; i <= v; i++) {
			if (!visited[i] && bipartite) { BFS(i); }//오류2 고친코드. 모든 노드에 대해서 탐색 진행.
		}

		cout << (bipartite ? "YES" : "NO") << '\n';
		fill_n(visited, 20001, 0);
	}
	return 0;

}

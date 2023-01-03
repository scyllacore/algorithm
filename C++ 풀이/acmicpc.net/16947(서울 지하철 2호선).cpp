#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int n;

vector<vector<int>> subway;
vector<int> cycle, cycleNode;
queue<int> disNode; // distance
bool visited[3001] = { 0 };
int shortDis[3001] = { 0 };

int start;
bool cycleCheck = 0;
bool nodeCheck = 0;


void DFS_btrk(int nodeN, int preNode) {

	if (cycleCheck == 1) {
		return;
	}

	int i, j;
	int nextNode;

	for (i = 0; i < subway[nodeN].size(); i++) {

		nextNode = subway[nodeN][i];

		if (nextNode == preNode) { continue; }

		if (nextNode == start) {
			cycle = cycleNode;
			cycleCheck = 1;
			return;
		}

		if (!visited[nextNode]) {
			visited[nextNode] = 1;
			cycleNode.push_back(nextNode);

			DFS_btrk(nextNode, nodeN);

			visited[nextNode] = 0;
			cycleNode.pop_back();
		}

	}


}

void BFS() {

	int i, nodeN, nextNode;

	while (!disNode.empty()) {

		nodeN = disNode.front();
		disNode.pop();

		for (i = 0; i < subway[nodeN].size(); i++) {

			nextNode = subway[nodeN][i];

			if (!visited[nextNode]) {
				visited[nextNode] = 1;
				shortDis[nextNode] = shortDis[nodeN] + 1;
				disNode.push(nextNode);
			}

		}
	}



}


int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> n;

	subway.assign(n + 1, vector<int>(0));

	int i, j, a, b;

	for (i = 1; i <= n; i++) {
		cin >> a >> b;
		subway[a].push_back(b);
		subway[b].push_back(a);
	}

	for (i = 1; i <= n; i++) {

		if (subway[i].size() < 2) { continue; }

		start = i;

		visited[i] = 1;
		cycleNode.push_back(i);

		DFS_btrk(i, 0);

		visited[i] = 0;
		cycleNode.pop_back();

		if (cycleCheck == 1) {
			break;
		}
	}


	for (i = 0; i < cycle.size(); i++) {
		disNode.push(cycle[i]);
		visited[cycle[i]] = 1;
	}

	BFS();

	for (i = 1; i <= n; i++) {
		cout << shortDis[i] << ' ';
	}

	return 0;

}
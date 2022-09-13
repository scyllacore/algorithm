#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int n;

vector<vector<int>> subway;
vector<int> cycleNode;
queue<int> disNode; // distance

bool visited[3001] = { 0 };
int shortDis[3001] = { 0 };

int start;


bool DFS_btrk(int nodeN, int preNode) {

	int i, j;
	int nextNode;

	for (i = 0; i < subway[nodeN].size(); i++) {

		nextNode = subway[nodeN][i];

		if (nextNode == preNode) { continue; }

		if (nextNode == start) {
			return 1;
		}

		if (!visited[nextNode]) {
			visited[nextNode] = 1;
			cycleNode.push_back(nextNode);

			if (DFS_btrk(nextNode, nodeN)) return 1;

			visited[nextNode] = 0;
			cycleNode.pop_back();
		}

	}

	return 0;

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

		if (DFS_btrk(i, 0)) { break; }

		visited[i] = 0;
		cycleNode.pop_back();

	}


	for (i = 0; i < cycleNode.size(); i++) {
		disNode.push(cycleNode[i]);
		visited[cycleNode[i]] = 1;
	}

	BFS();

	for (i = 1; i <= n; i++) {
		cout << shortDis[i] << ' ';
	}

	return 0;

}
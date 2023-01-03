#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, m;
vector<vector<int>> friendsGraph;
bool visited[2000] = { 0 };

void DFS_btrk(int numF, int depth) {
	
	int i;

	if (depth > 5) {
		cout << 1;
		exit(0);
	}

	for (i = 0; i < friendsGraph[numF].size(); i++) {

		if (visited[friendsGraph[numF][i]]) continue;
		
		visited[friendsGraph[numF][i]] = 1;
		DFS_btrk(friendsGraph[numF][i], depth + 1);
		visited[friendsGraph[numF][i]] = 0;

	}


}


int main() {

	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> n >> m;

	friendsGraph.assign(n, vector<int>(0));

	int i, j;
	int a, b;

	for (i = 0; i < m; i++) {
		cin >> a >> b;
		friendsGraph[a].push_back(b);
		friendsGraph[b].push_back(a);
	}

	for (i = 0; i < n; i++) {
		sort(friendsGraph[i].begin(), friendsGraph[i].end());
		friendsGraph[i].erase(unique(friendsGraph[i].begin(), friendsGraph[i].end()), friendsGraph[i].end());
	}

	for (i = 0; i < n; i++) {
		visited[i] = 1;
		DFS_btrk(i, 2);
		visited[i] = 0;
	}

	cout << 0;

	return 0;

}
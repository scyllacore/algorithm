#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> graphNet;
bool visited[101] = { 0,1 };

void DFS_btrk(int node) {

	int i;

	for (i = 0; i < graphNet[node].size(); i++) {

		int nextNet = graphNet[node][i];

		if (!visited[nextNet]) {
			visited[nextNet] = 1;
			DFS_btrk(nextNet);
		}

	}

}


int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	int nCom, nPair;
	cin >> nCom >> nPair;

	graphNet.assign(nCom + 1,vector<int>(0));

	int i,a,b;

	for (i = 0; i < nPair; i++) {
		cin >> a >> b;
		
		graphNet[a].push_back(b);
		graphNet[b].push_back(a);
	}

	DFS_btrk(1);

	int ans = 0;
	for (i = 1; i <= nCom; i++) {
		if (visited[i] == 1) { ans++; }
	}

	cout << ans-1;

	return 0;


}
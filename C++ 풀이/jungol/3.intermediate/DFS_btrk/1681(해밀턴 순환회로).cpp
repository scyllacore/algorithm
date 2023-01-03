#include <iostream>
#include <algorithm>

using namespace std;

int mapNN[14][14];
bool visited[14] = { 0,1 };
int route[14] = { 0,1 };
int n, minAns = (int)1e6;


void DFS_btrk(int depth,int sum) {

	if (sum > minAns) return;

	int i;

	if (depth > n) {

		if (mapNN[route[n]][route[1]] != 0) {
			sum += mapNN[route[n]][route[1]];
			minAns = min(sum, minAns);
		}

		return;
	}

	for (i = 1; i <= n; i++) {
		if (visited[i] || !mapNN[route[depth-1]][i]) continue;

		visited[i] = 1;
		route[depth] = i;
		DFS_btrk(depth + 1,sum+mapNN[route[depth-1]][route[depth]]);
		visited[i] = 0;

	}

}

int main() {

	cin >> n;

	int i, j;
	for (i = 1; i <= n; i++) {
		for (j = 1; j <= n; j++) {
			cin >> mapNN[i][j];
		}
	}

	DFS_btrk(2,0);

	cout << minAns;

}

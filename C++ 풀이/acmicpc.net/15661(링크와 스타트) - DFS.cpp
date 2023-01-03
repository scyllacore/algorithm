#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;


int stats[21][21] = { {0} };
int n;
int minVal = 99999, maxDepth;
bool teamCheck[21] = { 0 };

void DFS_btrk(int start, int depth) {

	int i;

	if (depth > maxDepth) {
		
		int j;

		int teamS = 0, teamL = 0;

		for (i = 1; i <= n - 1; i++) {
			for (j = i + 1; j <= n; j++) {
				if (teamCheck[i] && teamCheck[j]) { teamS += (stats[i][j] + stats[j][i]); }
				if (!teamCheck[i] && !teamCheck[j]) { teamL += (stats[i][j] + stats[j][i]); }
			}
		}

		int tmp = abs(teamS - teamL);
		minVal = min(tmp, minVal);
		return;
	}

	for (i = start; i <= n; i++) {
		teamCheck[i] = 1;
		DFS_btrk(i + 1, depth + 1);
		teamCheck[i] = 0;
	}

}


int main() {

	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> n;

	int i, j;

	for (i = 1; i <= n; i++) {
		for (j = 1; j <= n; j++) {
			cin >> stats[i][j];
		}
	}

	for (i = 1; i < n; i++) {
		maxDepth = i;
		DFS_btrk(1, 1);
	}

	cout << minVal;

	return 0;

}
#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>

using namespace std;

int main() {

	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	int stats[20][20] = { {0} };

	int n;
	cin >> n;

	int i, j;

	for (i = 0; i < n; i++) {
		for (j = 0; j < n; j++) {
			cin >> stats[i][j];
		}
	}

	int loop, minVal = 99999;
	vector<int>teamS, teamL;

	for (loop = 0; loop < (1 << n); loop++) {

		teamL.clear(), teamS.clear(); // vector<int>teamS, teamL -> 새로 만드는 것보다 clear가 속도가 더 빠르다.

		int teamSval = 0, teamLval = 0;

		for (int k = 0; k < n; k++) {
			if (loop & (1 << k)) {
				teamS.push_back(k);
			}
			else {
				teamL.push_back(k);
			}
		}

		if (teamS.size() != teamL.size()) continue;

		for (i = 0; i < n / 2 - 1; i++) {
			for (j = i + 1; j < n / 2; j++) {

				teamSval += stats[teamS[i]][teamS[j]] + stats[teamS[j]][teamS[i]];
				teamLval += stats[teamL[i]][teamL[j]] + stats[teamL[j]][teamL[i]];
			}
		}

		int tmp = abs(teamSval - teamLval);
		minVal = min(tmp, minVal);
	}

	cout << minVal;

	return 0;

}
#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;


int ans = (int)1e5;

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);


	int n;
	cin >> n;

	int stats[20][20];
	int i, j;

	for (i = 0; i < n; i++) {
		for (j = 0; j < n; j++) {
			cin >> stats[i][j];
		}
	}

	vector<int> teamS, teamL;

	for (int bitCase = 1; bitCase < (1 << n) - 1; bitCase++) {

		teamS.clear(), teamL.clear();

		for (i = 0; i < n; i++) {
			if (bitCase & (1 << i)) {
				teamS.push_back(i);
			}
			else {
				teamL.push_back(i);
			}
		}

		int scoreS = 0, scoreL = 0;

		for (i = 0; i < teamS.size() - 1; i++) {
			for (j = i + 1; j < teamS.size(); j++) {
				scoreS += stats[teamS[i]][teamS[j]] + stats[teamS[j]][teamS[i]];
			}
		}

		for (i = 0; i < teamL.size() - 1; i++) {
			for (j = i + 1; j < teamL.size(); j++) {
				scoreL += stats[teamL[i]][teamL[j]] + stats[teamL[j]][teamL[i]];
			}
		}

		ans = min(abs(scoreS - scoreL), ans);
	}


	cout << ans;

	return 0;

}
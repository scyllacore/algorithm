#include <iostream>
#include <algorithm>
#include <unordered_map>

using namespace std;

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	int d, n;
	cin >> d >> n;

	vector<int> dVec(d);
	unordered_map<int, int> dCount;

	for (int i = 0; i < d; i++) {
		cin >> dVec[i];
		dCount[dVec[i]]++;
	}

	sort(dVec.begin(), dVec.end());

	int ans = 0;
	int pizza;

	for (int i = 0; i < n; i++) {
		cin >> pizza;
		int idx = upper_bound(dVec.begin(), dVec.end(), pizza) - dVec.begin();

		if (idx < dVec.size() && pizza <= dVec[idx]) {

		}

	}



}

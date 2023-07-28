#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/*
int selectTitle(vector<title>& titles, int strength) {
	for (int i = 1; i <= titles.size(); i++) {
		if (strength >= titles[i - 1].strength && strength <= titles[i].strength) {
			return i;
		}
	}

	return 0;
}
*/

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	int n, m;
	cin >> n >> m;

	vector<string> titleNames(n);
	vector<int> strengths(n);

	/*
	titleNames[0] = "none";
	strengths[0] = 0;
	*/

	for (int i = 0; i < n; i++) {
		cin >> titleNames[i] >> strengths[i];
	}

	int strength;

	for (int i = 0; i < m; i++) {
		cin >> strength;

		int idx = lower_bound(strengths.begin(), strengths.end(), strength) - strengths.begin(); //selectTitle(titles, strength);

		cout << titleNames[idx] << '\n';
	}

	return 0;
}
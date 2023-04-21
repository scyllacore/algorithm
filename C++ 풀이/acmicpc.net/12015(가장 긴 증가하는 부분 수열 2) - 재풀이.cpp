#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	int n;
	cin >> n;

	vector<int>	sequence(n);

	for (int i = 0; i < n; i++) {
		cin >> sequence[i];
	}

	vector<int> lis;

	for (int i = 0; i < n; i++) {
		int idx = lower_bound(lis.begin(), lis.end(), sequence[i]) - lis.begin();

		if (idx + 1 > lis.size()) { // lis.size() -1 하지 말 것.
			lis.push_back(sequence[i]);
		}
		else {
			lis[idx] = sequence[i];
		}
	}

	cout << lis.size();

	return 0;
}

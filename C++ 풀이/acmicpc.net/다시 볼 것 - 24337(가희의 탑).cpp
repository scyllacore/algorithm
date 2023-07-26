#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	int n, a, b;

	cin >> n >> a >> b;

	if (a + b - 1 > n) {
		cout << -1;
		return 0;
	}

	vector<int> building;

	for (int i = 1; i < a; i++) {
		building.push_back(i);
	}

	building.push_back(max(a, b));

	for (int i = b - 1; i >= 1; i--) {
		building.push_back(i);
	}

	vector<int> adding(n - (a + b - 1), 1);

	vector<int> ans;

	if (a == 1) {
		ans.insert(ans.end(), building.begin(), building.begin() + 1);
		ans.insert(ans.end(), adding.begin(), adding.end());
		ans.insert(ans.end(), building.begin() + 1, building.end());
	}
	else {
		ans.insert(ans.end(), adding.begin(), adding.end());
		ans.insert(ans.end(), building.begin(), building.end());
	}

	for (auto val : ans) {
		cout << val << ' ';
	}

	return 0;
}
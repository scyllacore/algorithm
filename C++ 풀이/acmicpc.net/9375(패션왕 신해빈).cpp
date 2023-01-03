#include <iostream>
#include <map>

using namespace std;

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	int tc;
	cin >> tc;

	map<string, int> hyebin;
	string clothes, category;
	int n, i;

	while (tc--) {

		cin >> n;

		for (i = 0; i < n; i++) {
			cin >> clothes >> category;

			if (hyebin.find(category) == hyebin.end()) {
				hyebin.insert({ category ,2 });
			}
			else {
				hyebin[category] += 1;
			}
		}

		int ans = 1;

		for (auto ptr = hyebin.begin(); ptr != hyebin.end(); ptr++) {
			ans *= ptr->second;
		}
		cout << ans - 1 << '\n';

		hyebin.clear();
	}

	return 0;
}

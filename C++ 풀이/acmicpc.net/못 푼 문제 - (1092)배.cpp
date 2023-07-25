#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	int n;
	cin >> n;

	vector<int> crain(n);

	for (int i = 0; i < n; i++) {
		cin >> crain[i];
	}

	int m;
	cin >> m;

	vector<int> box(m);

	for (int i = 0; i < m; i++) {
		cin >> box[i];
	}

	sort(crain.begin(), crain.end());
	sort(box.begin(), box.end());

	int ans = 0;

	for (; !box.empty();) {

		int crainSize = n;

		for (int i = 0; i < n && !box.empty(); i++) {
			int idx = lower_bound(box.begin(), box.end(), crain[i]) - box.begin();

			cout << idx << '\n';

			if (idx >= crain.size()) {
				crainSize--;
				box.pop_back();
			}
			else if (idx < crain.size() && box[idx] <= crain[i]) {
				crainSize--;
				box.erase(box.begin() + idx);
			}

			for (int j = 0; j < box.size(); j++) {
				cout << box[j] << ' ';
			}
			cout << '\n';

		}

		if (crainSize == 0 || box.empty()) {
			ans++;
		}
		else {
			ans = -1;
			break;
		}

	}

	cout << ans;

	return 0;
}
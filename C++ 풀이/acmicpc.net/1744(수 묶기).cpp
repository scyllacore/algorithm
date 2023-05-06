#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
#include <numeric>

using namespace std;

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	int n;
	cin >> n;

	vector<int> pos, neg, zero, res;

	int tmp;
	for (int i = 0; i < n; i++) {
		cin >> tmp;

		if (tmp == 0) {
			zero.push_back(0);
		}
		else if (tmp == 1) {
			res.push_back(1);
		}
		else {
			if (tmp > 0) {
				pos.push_back(tmp);
			}
			else {
				neg.push_back(tmp);
			}
		}
	}

	sort(pos.begin(), pos.end(), greater<>());
	sort(neg.begin(), neg.end());


	if (!pos.empty() && pos.size() % 2 != 0) {
		res.push_back(pos.back());
		pos.pop_back();
	}

	for (int i = 1; i < pos.size(); i += 2) {
		res.push_back(pos[i] * pos[i - 1]);
	}

	if (!neg.empty() && neg.size() % 2 != 0) {
		if (!zero.empty()) {
			neg.pop_back();
		}
		else {
			res.push_back(neg.back());
			neg.pop_back();
		}
	}

	for (int i = 1; i < neg.size(); i += 2) {
		res.push_back(neg[i] * neg[i - 1]);
	}

	cout << accumulate(res.begin(), res.end(), 0);

	return 0;
}
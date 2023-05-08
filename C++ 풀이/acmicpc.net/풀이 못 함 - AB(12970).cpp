#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

bool checkChangeIdx(vector<int>& changeIdx, int n, int k, int& start) {
	for (int i = start; i >= 0; i--) {
		if (k - (n - i - 1) == 0) {
			changeIdx.push_back(i);
			return 1;
		}
		else if (k - (n - i - 1) > 0) {
			k = k - (n - i - 1) + 1;
			changeIdx.push_back(i);
		}
	}

	return 0;
}

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	int n, k;
	cin >> n >> k;

	string ans = "";

	for (int i = 0; i < n; i++) {
		ans.append("B");
	}

	vector<int> changeIdx;

	for (int i = n - 1; i >= 0; i--) {
		changeIdx.clear();
		bool res = checkChangeIdx(changeIdx, n, k, i);

		if (res) {
			for (int idx : changeIdx) {
				ans[idx] = 'A';
			}

			cout << ans;
			return 0;
		}
	}

	cout << -1;

	return 0;
}
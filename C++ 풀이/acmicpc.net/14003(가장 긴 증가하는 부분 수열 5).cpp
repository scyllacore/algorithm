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

	vector<int> arr(n), lis, lenV(n);

	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	int maxIdx = 0;


	for (int i = 0; i < n; i++) {
		int idx = lower_bound(lis.begin(), lis.end(), arr[i]) - lis.begin();

		if (idx >= lis.size()) {
			lis.push_back(arr[i]);
		}
		else {
			lis[idx] = arr[i];
		}

		lenV[i] = idx + 1;

		if (lenV[i] > lenV[maxIdx]) {
			maxIdx = i;
		}
	}

	cout << lis.size() << '\n';

	vector<int> ans;
	int maxVal = lenV[maxIdx];

	for (int i = maxIdx; i >= 0; i--) {
		if (maxVal == lenV[i]) {
			ans.push_back(arr[i]);
			maxVal--;
		}
	}

	for (int i = ans.size() - 1; i >= 0; i--) {
		cout << ans[i] << ' ';
	}

	return 0;

}
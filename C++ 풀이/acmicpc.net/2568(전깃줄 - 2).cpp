#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct connect {
	int a, b;
};

bool cmp(connect& info1, connect& info2) {
	return info1.a < info2.a;
}

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	int n;
	cin >> n;

	vector<connect> conInfo(n);
	vector<int> lis, lenV(n);

	for (int i = 0; i < n; i++) {
		cin >> conInfo[i].a >> conInfo[i].b;
	}

	sort(conInfo.begin(), conInfo.end(), cmp);

	int maxIdx = 0;

	for (int i = 0; i < n; i++) {
		int idx = lower_bound(lis.begin(), lis.end(), conInfo[i].b) - lis.begin();

		if (idx >= lis.size()) {
			lis.push_back(conInfo[i].b);
		}
		else {
			lis[idx] = conInfo[i].b;
		}

		lenV[i] = idx + 1;

		if (lenV[i] > lenV[maxIdx]) {
			maxIdx = i;
		}
	}

	cout << n - lis.size() << '\n';

	int maxVal = lenV[maxIdx];

	vector<int> ans;

	for (int i = n - 1; i >= 0; i--) {
		if (maxVal == lenV[i]) {
			maxVal--;
		}
		else {
			ans.push_back(conInfo[i].a);
		}
	}

	reverse(ans.begin(), ans.end());

	for (int i = 0; i < ans.size(); i++) {
		cout << ans[i] << '\n';
	}

	return 0;

}
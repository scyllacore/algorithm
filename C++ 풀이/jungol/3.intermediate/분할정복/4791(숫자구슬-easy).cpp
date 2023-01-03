#include <iostream>
#include <vector>
using namespace std;

int n, m;
int marble[301];


bool maxMarbleSum(int val) {
	int cnt = 1, sum = 0;
	for (int i = 0; i < n; ++i) {
		if (marble[i] > val)return false;
		if (sum + marble[i] <= val) {
			sum += marble[i];
		}
		else {
			++cnt;
			sum = marble[i];
		}
	}

	return cnt <= m;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n >> m;

	for (int i = 0; i < n; ++i)
		cin >> marble[i];

	int l = 1, r = n * 100;

	while (l <= r) {
		int mid = (l + r) / 2;
		if (maxMarbleSum(mid)) {
			r = mid - 1;
		}
		else {
			l = mid + 1;
		}
	}

	cout << l << endl;

	int cnt = 0, sum = 0, group = 1;

	vector<int> ans;

	for (int i = 0; i < n; ++i) {
		sum += marble[i];
		if (sum > l) {
			ans.push_back(cnt);
			sum = marble[i];
			cnt = 0;
			++group;
		}
		++cnt;
	}

	ans.push_back(cnt);

	int pos = ans.size() - 1;
	while (group < m) {
		if (ans[pos] == 1) {
			--pos;
		}
		else {
			--ans[pos];
			ans.push_back(1);
			++group;
		}
	}

	/*for (int val : ans) {
		cout << val << " ";
	}*/
	return 0;
}
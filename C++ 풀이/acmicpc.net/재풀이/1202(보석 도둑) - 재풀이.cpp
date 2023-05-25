#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

struct jewelry {
	int m, v;
};

bool jCmp(jewelry& j1, jewelry& j2) {
	return j1.m < j2.m;
}

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	int n, k;
	cin >> n >> k;

	vector<jewelry> jewelryV(n);
	vector<int> bagV(k);

	for (int i = 0; i < n; i++) {
		cin >> jewelryV[i].m >> jewelryV[i].v;
	}

	for (int i = 0; i < k; i++) {
		cin >> bagV[i];
	}

	sort(jewelryV.begin(), jewelryV.end(), jCmp);
	sort(bagV.begin(), bagV.end());

	priority_queue<int> pricePQ;

	int idx = 0;

	unsigned long long ans = 0;

	for (int i = 0; i < k; i++) {

		for (; idx < n && jewelryV[idx].m <= bagV[i];) {
			pricePQ.push(jewelryV[idx++].v);
		}

		if (!pricePQ.empty()) {
			ans += pricePQ.top();
			pricePQ.pop();
		}
	}

	cout << ans;
	return 0;
}
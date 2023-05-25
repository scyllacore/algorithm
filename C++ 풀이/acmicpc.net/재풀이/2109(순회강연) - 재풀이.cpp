#include <iostream>
#include <queue>
#include <vector>
#include <functional>

using namespace std;

struct lecture {
	int p, d;
};

bool cmp(lecture& l1, lecture& l2) {
	return l1.d < l2.d;
}

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	int n;
	cin >> n;

	vector<lecture> lecV(n);

	for (int i = 0; i < n; i++) {
		cin >> lecV[i].p >> lecV[i].d;
	}

	sort(lecV.begin(), lecV.end(), cmp); // 늦게 강연을해도 되는 강의를 가장 늦게 하기 위해 처리하는 과정이다.

	priority_queue<int, vector<int>, greater<>> pq;

	int ans = 0;

	for (int i = 0; i < n; i++) {
		pq.push(lecV[i].p);
		ans += lecV[i].p;

		if (pq.size() > lecV[i].d) {
			ans -= pq.top();
			pq.pop();
		}
	}

	cout << ans;
	return 0;
}
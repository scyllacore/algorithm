#include <iostream>
#include <queue>

using namespace std;

struct cmp {
	bool operator()(const size_t& a, const size_t& b) {
		return a > b;
	}
};

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	int tc;
	cin >> tc;

	int k, size;

	priority_queue<size_t, vector<size_t>, cmp> pq;

	size_t first, second;
	size_t ans;

	for (; tc--;) {
		cin >> k;

		for (int i = 0; i < k; i++) {
			cin >> size;
			pq.push(size);
		}

		ans = 0;

		for (; pq.size() > 1;) {
			first = pq.top();
			pq.pop();

			second = pq.top();
			pq.pop();

			ans += first + second;
			pq.push(first + second);
		}
		pq.pop(); // 잘했는데 자료형을 잘못써서 틀렸다.

		cout << ans << '\n';
	}

	return 0;
}
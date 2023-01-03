#include <iostream>
#include <queue>
#include <functional>

using namespace std;

int main() {

	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	priority_queue<int, vector<int>, greater<int>> pq;

	int tc;
	cin >> tc;

	int n;

	while ((tc--) > 0) {

		cin >> n;

		if (!n) {
			if (pq.empty()) {
				cout << 0 << '\n';
			}
			else {
				cout << pq.top() << '\n';
				pq.pop();
			}
		}

		else {
			pq.push(n);
		}


	}

	return 0;
}



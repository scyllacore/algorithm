#include <iostream>
#include <vector>
#include <cmath>
#include <queue>

using namespace std;

struct cmp {

	bool operator()(const int& a, const int& b) {

		int tmpA = abs(a), tmpB = abs(b);

		if (tmpA == tmpB) {
			return a > b;
		}
		
		return tmpA > tmpB;
	}

};

int main() {

	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	int tc, n;
	cin >> tc;

	priority_queue<int, vector<int>, cmp> pq;

	while (tc--) {

		cin >> n;

		if (n == 0) {
			if (pq.empty()) {
				cout << 0;
			}
			else {
				cout << pq.top();
				pq.pop();

			}
			cout << '\n';
		}
		else
		{
			pq.push(n);
		}

	}

	return 0;
}

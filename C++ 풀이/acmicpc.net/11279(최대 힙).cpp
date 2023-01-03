#include <iostream>
#include <vector>
#include <queue>
#include <functional>

using namespace std;

int main() {

	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	priority_queue<int, vector<int>,less<>> pq;

	int tc,n;

	cin >> tc;

	while (tc--) {

		cin >> n;

		if (n == 0) {
			if (pq.empty()) {
				cout << '0';
			}
			else {
				cout << pq.top();
				pq.pop();
			}
			cout << '\n';
		}
		else {
			pq.push(n);
		}
	}

	return 0;

}

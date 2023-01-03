#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

typedef struct {
	int idx;
	int priority;
}Print;

int calOrder(queue<Print>& q, int arr[], int m) {

	int i;
	int order = 1;

	for (i = 9; i >= 1; i--) {
		for (; arr[i] > 0;) {
			if (q.front().priority == i) {

				if (q.front().idx == m) {
					return order;
				}
				order++;
				arr[i]--;
				q.pop();
			}
			else {
				q.push(q.front());
				q.pop();
			}
		}
	}

	return -1;

}

int main() {

	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	int tc, i;
	cin >> tc;

	int n, m;

	for (; (tc--) > 0; ) {

		cin >> n >> m;

		Print tmp;
		queue<Print> q;
		int* arr = new int[10]{ 0, };

		for (i = 0; i < n; i++) {
			cin >> tmp.priority;

			arr[tmp.priority]++;
			tmp.idx = i;

			q.push(tmp);
		}

		cout << calOrder(q, arr, m) << '\n';
	}

	return 0;
}


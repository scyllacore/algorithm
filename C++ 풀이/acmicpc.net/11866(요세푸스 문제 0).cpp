#include <iostream>
#include <queue>

using namespace std;

int main() {

	cin.tie(NULL);
	cout.tie(NULL);

	queue<int> Josephus;
	int n, k, i;
	cin >> n >> k;

	for (i = 1; i <= n; i++) {
		Josephus.push(i);
	}

	cout << '<';

	for (; !Josephus.empty();) {

		for (i = 0; i < k - 1; i++) {
			Josephus.push(Josephus.front());
			Josephus.pop();
		}

		if (Josephus.size() > 1) {
			cout << Josephus.front() << ", ";
		}
		else {
			cout << Josephus.front();
		}

		Josephus.pop();

	}

	cout << '>';
	return 0;

}

//1 2 3 4 5 6 7
//4 5 6 7 1 2
//7 1 2 4 5
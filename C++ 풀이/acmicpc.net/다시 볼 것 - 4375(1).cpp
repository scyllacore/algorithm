#include <iostream>

using namespace std;

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	int n, i;

	for (; cin >> n;) {

		unsigned long long one = 1;

		for (i = 1;; i++) {
			if (one % n == 0) {
				cout << i << '\n';
				break;

			}
			one = one * 10 + 1;
			one = one % n;
		}
	}

	return 0;

}

//https://st-lab.tistory.com/214
//https://nanyoungkim.tistory.com/115
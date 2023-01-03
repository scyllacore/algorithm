#include <iostream>

using namespace std;

int main() {

	int n;

	cin >> n;

	int i,sum=0;

	for (i = 1; ; i++) {
		sum += i;

		if (sum >= n) {
			sum -= i;
			break;
		}

	}

	int val = n - sum;

	if (i % 2 == 1) {
		cout << i-val+1 <<'/' << val;
	}
	else {
		cout << val << '/' << i - val + 1;
	}

}
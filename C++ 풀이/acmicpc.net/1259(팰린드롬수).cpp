#include <iostream>

using namespace std;

int main() {

	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	int n;

	for (;;) {

		cin >> n;

		if (n == 0) return 0;

		int revVal = 0,orgVal = n;
		

		while (n > 0) {
			revVal = revVal * 10 + n % 10;
			n /= 10;
		}

		cout << (revVal == orgVal ? "yes" : "no") << '\n';

		
	}

	return 0;

}

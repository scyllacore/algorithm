#include <iostream>

using namespace std;

int main() {

	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	int n;
	cin >> n;

	unsigned long long ans = 0;

	int nCnt = 9, len = 1;

	while (1) {

		if (n - nCnt <= 0) { // n - nCnt < 0 or n - nCnt <= 0
			ans += n * len;
			break;

		}
		else {
			ans += nCnt * (len++);
		}

		n -= nCnt;
		nCnt *= 10;

	}

	cout << ans;

}
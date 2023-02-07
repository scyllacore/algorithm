#include <iostream>

using namespace std;

int getGcd(int a, int b) {
	int tmp;

	for (; b != 0;) {
		tmp = a % b;
		a = b;
		b = tmp;
	}

	return a;
}

int getLcm(int a, int b) {
	return a * b / getGcd(a, b);
}

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	int m, n, x, y;
	int tc;

	cin >> tc;

	for (; tc--;) {
		cin >> m >> n >> x >> y;

		int maxDay = getLcm(m, n);

		int ansDay = x;
		int yTmp;

		for (;;) {
			yTmp = ansDay % n == 0 ? n : ansDay % n;

			if (ansDay > maxDay) {
				cout << -1 << '\n';
				break;
			}

			if (yTmp == y) {
				cout << ansDay << '\n';
				break;
			}

			ansDay += m;
		}
	}

}
#include <iostream>

using namespace std;

int gcd(int x, int y) {

	int tmp;
	//24 18 -> 18 6 -> 6 0
	while (y != 0) {
		tmp = x % y;
		x = y;
		y = tmp;
	}

	return  x;

}

int lcm(int x, int y) {
	return x * y / gcd(x, y);
}


int main() {

	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	int tc;
	cin >> tc;

	while ((tc--) > 0) {

		int M, N, x, y;
		cin >> M >> N >> x >> y;

		int maxCnt = lcm(M, N),ansCnt=x;
		int yCnt=x;


		for (int i = 0; ; i++) {
			int yTmp = (yCnt % N == 0 ? N : yCnt % N);

			if (maxCnt < ansCnt) {
				cout << -1 << '\n';
				break;
			}

			if (yTmp == y) {
				cout << ansCnt << '\n';
				break;
			}
			ansCnt = (yCnt += M);
		}

	}



}
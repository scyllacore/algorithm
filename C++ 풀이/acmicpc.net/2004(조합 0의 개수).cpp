#include <iostream>

using namespace std;

int pow2Check(int num) {

	int sum = 0;

	for (; num >= 2;) {
		sum += num / 2;
		num /= 2;
	}

	return sum;
}

int pow5Check(int num) {

	int sum = 0;

	for (; num >= 5;) {
		sum += num / 5;
		num /= 5;
	}

	return sum;

}


int zeroCheck(int n, int m) {

	int fiveCnt = pow5Check(n) - pow5Check(m) - pow5Check(n - m);
	int zeroCnt = pow2Check(n) - pow2Check(m) - pow2Check(n - m);

	return fiveCnt > zeroCnt ? zeroCnt : fiveCnt;

}

int main()
{
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	int n, m;

	cin >> n >> m;

	cout << zeroCheck(n, m);

}
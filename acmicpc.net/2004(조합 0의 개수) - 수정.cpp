#include <iostream>
#include <algorithm>

using namespace std;

int pow2Check(int num) {

	int cnt = 0;

	for (long i = 2; i <= num; i *= 2) { // long , long long 둘 다 8byte 취급 됨. i값이 int 범위를 벗어날 조건에 안 맞는 경우 생각. 
		cnt += num / i;
	}

	return cnt;
}

int pow5Check(int num) {

	int cnt = 0;

	for (long i = 5; i <= num; i *= 5) {
		cnt += num / i;
	}

	return cnt;

}


int zeroCheck(int n, int m) {

	int fiveCnt = pow5Check(n) - pow5Check(m) - pow5Check(n - m);
	int zeroCnt = pow2Check(n) - pow2Check(m) - pow2Check(n - m);

	return min(fiveCnt, zeroCnt);

}

int main()
{
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	int n, m;

	cin >> n >> m;

	cout << zeroCheck(n, m);

	return 0;

}
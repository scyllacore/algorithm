#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

bool broken[10];

int numPress(int n)
{
	if (n == 0) {
		if (broken[0]) {
			return 0;
		}
		else {
			return 1;
		}
	}

	int pressCnt = 0;

	while (n > 0) {
		if (broken[n % 10]) { return 0; }
		n /= 10;
		pressCnt++;
	}

	return pressCnt;

}


int main() {

	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	int n, m, brkBtn;
	int i, ans;

	cin >> n >> m;

	for (i = 0; i < m; i++) {
		cin >> brkBtn;
		broken[brkBtn] = 1;
	}

	ans = abs(n - 100);

	for (i = 0; i <= 999999; i++) {
		/*
		최대값은 문제에서 500000이라고 되어있으나
		리모콘이 9를 제외하고 모두 고장났다면
		999999를 눌러서 찾는 경우도 포함되어야 하므로
		최대값을 999999으로 설정한다.
		*/
		int numPressCnt = numPress(i);

		if (numPressCnt > 0) {
			int leftover = abs(n - i);
			int totalPress = leftover + numPressCnt;

			ans = min(totalPress, ans);
		}
	}

	cout << ans;
	return 0;


}
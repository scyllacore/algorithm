#include <iostream>
#include <algorithm>

using namespace std;

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	int n, m, k;
	cin >> n >> m >> k;

	/*
	int ans = 0;

	for (int i = 0; i <= k; i++) {
		int nk = n - i <= 0 ? 0 : n - i;
		int mk = m - (k - i) <= 0 ? 0 : m - (k - i);

		nk = nk / 2;
		ans = max(min(nk, mk), ans);
	}

	cout << ans;
	*/

	/*
	int max = N / 2 < M ? N / 2 : M;

	//전체에서 최대값을 제외한 나머지 값을
	//K에 빼준다.
	K -= N + M - 3 * max;

	//K가 0보다 크다면
	//3으로 나눈 몫만큼 max에서 빼준다.
	if (K > 0) {
		K--;
		max -= K / 3 + 1;
	}

	printf("%d\n", max);
	return 0;
	*/

	for (int i = 1; i <= k; i++) {
		if (n / 2 >= m) {
			n -= 1;
		}
		else {
			m -= 1;
		}
	}
	cout << min(n / 2, m);

	return 0;
}
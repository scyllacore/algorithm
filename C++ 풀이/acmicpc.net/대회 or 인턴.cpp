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

	//��ü���� �ִ밪�� ������ ������ ����
	//K�� ���ش�.
	K -= N + M - 3 * max;

	//K�� 0���� ũ�ٸ�
	//3���� ���� ��ŭ max���� ���ش�.
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
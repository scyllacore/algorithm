#include <iostream>

using namespace std;

#define SIZE (int)2e5

int numCnt[SIZE + 1] = { 0 };

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	int n;
	cin >> n;

	int m;
	cin >> m;

	if (m > SIZE) {
		cout << 0;
		return 0;
	}

	int num;

	for (int i = 0; i < n; i++) {
		cin >> num;
		numCnt[num]++;
	}

	int ans = 0;

	for (int low = 0; low <= SIZE / 2; low++) {
		for (;;) { // numCnt[low] > 0 && numCnt[m - low] > 0 -> �ѹ��� �˻��ϸ� ���ڰ� ������ ������ 1�� ������ �� ������ �ȴ�.
			if (numCnt[low] <= 0) {
				break;
			}
			numCnt[low]--;

			if (numCnt[m - low] <= 0) {
				break;
			}
			numCnt[m - low]--;

			ans++;
		}
	}

	cout << ans;

	return 0;
}
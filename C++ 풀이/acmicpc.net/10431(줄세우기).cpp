#include <iostream>

using namespace std;

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	int tc;
	cin >> tc;

	int tcNum;
	int students[20];

	for (; tc--;) {
		cin >> tcNum;

		for (int i = 0; i < 20; i++) {
			cin >> students[i];
		}

		int movingCnt = 0;

		for (int i = 1; i < 20; i++) {
			for (int j = 0; j < i; j++) {
				if (students[j] > students[i]) {
					int tmp = students[i];

					for (int k = i; k > j; k--) {
						students[k] = students[k - 1];
						movingCnt++;
					}
					students[j] = tmp;
				}
			}
		}

		cout << tcNum << ' ' << movingCnt << '\n';
	}

	return 0;
}
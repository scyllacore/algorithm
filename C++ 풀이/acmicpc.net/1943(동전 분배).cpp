#include <iostream>

using namespace std;

#define MAX (int)5e4

struct coinInfo {
	int coin;
	int count;
};

bool dp[MAX + 1] = { 0 };

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	int n;
	int sum;
	coinInfo* coin;

	for (int tc = 3; tc > 0; tc--) {
		cin >> n;
		coin = new coinInfo[n];
		fill(&dp[0], &dp[MAX + 1], 0);
		sum = 0;

		for (int i = 0; i < n; i++) {
			cin >> coin[i].coin >> coin[i].count;
			sum += coin[i].coin * coin[i].count;
		}

		if (sum % 2 != 0) {
			cout << 0 << '\n';
			continue;
		}

		dp[0] = 1;

		for (int i = 0; i < n; i++) {
			for (int j = MAX; j >= coin[i].coin; j--) {
				if (dp[j - coin[i].coin]) { // top-down��� �̿�. ������ ���⼭ �ϳ� ����
					for (int k = 0; k < coin[i].count && j + k * coin[i].coin <= MAX; k++) { // �������� ���� ó��
						dp[j + k * coin[i].coin] = 1;
					}
				}
			}
		}

		if (dp[sum / 2]) {
			cout << 1;
		}
		else {
			cout << 0;
		}
		cout << '\n';
	}

	return 0;
}
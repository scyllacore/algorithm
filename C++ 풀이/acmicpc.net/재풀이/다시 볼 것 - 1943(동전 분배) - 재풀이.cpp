#include <iostream>
#include <algorithm>

using namespace std;

#define MAX (int)5e4 + 1

struct coin {
	int val;
	int cnt;
};


bool dp[MAX] = { 0 };

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	int n;

	for (int tc = 3; tc > 0; tc--) {
		cin >> n;
		coin* coins = new coin[n];

		int sum = 0;
		fill(&dp[0], &dp[MAX], 0);

		for (int i = 0; i < n; i++) {
			cin >> coins[i].val >> coins[i].cnt;
			sum += coins[i].val * coins[i].cnt;
		}

		if (sum % 2 != 0) {
			cout << 0 << '\n';
			continue;
		}

		dp[0] = 1;

		for (int i = 0; i < n; i++) {
			for (int j = MAX; j >= coins[i].val; j--) {
				// int j = coins[i].val; j <= MAX - 1; j++ �ȵ�.
				// top-down ������θ� �ߺ��Ǵ� ������ ���ο� ��츦 Ž���� �� �ִٴ� ���� �˾Ƶ���.
				// ���� �ε����� Ž���ϱ� ������(?)
				if (dp[j - coins[i].val]) {
					for (int k = 0; k < coins[i].cnt && j + coins[i].val * k < MAX; k++) {
						dp[j + coins[i].val * k] = 1;
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

//https://gusdnr69.tistory.com/263
//https://sdy-study.tistory.com/238
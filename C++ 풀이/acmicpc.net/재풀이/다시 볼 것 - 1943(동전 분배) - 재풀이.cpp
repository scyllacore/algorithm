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
				// int j = coins[i].val; j <= MAX - 1; j++ 안됨.
				// top-down 방식으로만 중복되는 경우없이 새로운 경우를 탐색할 수 있다는 것을 알아두자.
				// 이전 인덱스를 탐색하기 때문에(?)
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
#include <iostream>

using namespace std;

#define SIZE 30

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	long long dp[SIZE + 1][SIZE + 1];

	for (int h = 1; h <= SIZE; h++) {
		dp[0][h] = 1;
	}

	for (int w = 1; w <= SIZE; w++) {
		for (int h = 0; h <= SIZE; h++) {
			if (h == 0) {
				dp[w][0] = dp[w - 1][1];
			}
			else {
				dp[w][h] = dp[w - 1][h + 1] + dp[w][h - 1];
			}
		}
	}

	for (int w = 1; w <= 10; w++) {
		for (int h = 0; h <= 10; h++) {
			cout << dp[w][h] << ' ';
		}
		cout << '\n';
	}



	int n;

	for (; cin >> n;) {
		if (n == 0) {
			break;
		}

		cout << dp[n][0] << '\n';
	}

	return 0;
}

//https://ghqls0210.tistory.com/209

/*
#include <iostream>

using namespace std;

#define SIZE 30

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	long long dp[SIZE + 1][SIZE + 1] = {{0}};

	for (int h = 0; h <= SIZE; h++) {
		for (int w = h; w <= 30; w++) {
			if (h == 0) {
				dp[w][0] = 1;
			}
			else {
				dp[w][h] = dp[w - 1][h] + dp[w][h - 1];
			}
		}
	}

	/*for (int w = 1; w <= 10; w++) {
		for (int h = 0; h <= 10; h++) {
			cout << dp[w][h] << ' ';
		}
		cout << '\n';
	}

	int n;

	for (; cin >> n;) {
		if (n == 0) {
			break;
		}

		cout << dp[n][n] << '\n';
	}

	return 0;
}

//https://kimtaehyun98.tistory.com/67
*/
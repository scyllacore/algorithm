#include <iostream>
#include <vector>

using namespace std;

struct ball {
	int num[3];
	int strike;
	int ball;
};

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	int n;
	cin >> n;

	vector<ball> guessBall(n);

	string num;
	for (int i = 0; i < n; i++) {
		cin >> num;
		guessBall[i].num[0] = (int)(num[0] - '0');
		guessBall[i].num[1] = (int)(num[1] - '0');
		guessBall[i].num[2] = (int)(num[2] - '0');
		cin >> guessBall[i].strike >> guessBall[i].ball;
	}

	vector<ball> testBall;

	for (int i = 1; i <= 9; i++) {
		for (int j = 1; j <= 9; j++) {
			for (int k = 1; k <= 9; k++) {
				if (i != j && i != k && j != k) {
					testBall.push_back({ { i,j,k }, 0, 0 });
				}
			}
		}
	}


	int ans = 0;

	for (ball& tb : testBall) {

		int cnt = 0;

		for (int i = 0; i < n; i++) {
			int tbStrike = 0;

			for (int j = 0; j < 3; j++) {
				if (tb.num[j] == guessBall[i].num[j]) {
					tbStrike++;
				}
			}

			int tbBall = 0;

			for (int j = 0; j < 3; j++) {
				int pos1 = (j == 0) ? 1 : 0;
				int pos2 = (j == 2) ? 1 : 2;

				if (tb.num[j] == guessBall[i].num[pos1] || tb.num[j] == guessBall[i].num[pos2]) {
					tbBall++;
				}
			}

			if (tbStrike == guessBall[i].strike && tbBall == guessBall[i].ball) {
				cnt++;
			}
		}

		if (cnt == n) {
			ans++;
		}
	}

	cout << ans;

	return 0;
}
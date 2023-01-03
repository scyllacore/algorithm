#include <iostream>
#include <algorithm>
#include <climits>

using namespace std;

int ground[255000];


int main() {

	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);


	int n, m, b;
	cin >> n >> m >> b;

	int i, j;

	for (i = 0; i < n * m; i++) {
		cin >> ground[i];
	}

	int low = *min_element(ground, ground + (n * m));
	int high = *max_element(ground, ground + (n * m));


	//cout << low << ' ' << high;

	int takeTime, bCnt, flag;

	int ansTime = INT_MAX, ansLow = 0; // 원래 맞는건데.. 아무리봐도 맞는데.. ㅠㅠ 최댓값 설정은 확실히하자!.


	while (low <= high) {

		flag = takeTime = 0;
		bCnt = b;


		for (i = 0; i < n * m; i++) {
			if (low < ground[i]) {
				takeTime += 2 * (ground[i] - low);
				bCnt += (ground[i] - low);
			}
		}

		for (i = 0; i < n * m; i++) {
			if (low > ground[i]) {
				takeTime += (low - ground[i]);
				bCnt -= (low - ground[i]);
				if (bCnt < 0) {
					flag = 1;
					break;
				}
			}
		}

		low++;

		if (flag == 1) { continue; }

		if (takeTime <= ansTime) {
			ansTime = takeTime;
			ansLow = low - 1;
		}

	}


	cout << ansTime << ' ' << ansLow;

}
#include <iostream>
#include <algorithm>

using namespace std;

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	int n;
	cin >> n;

	string ball;
	cin >> ball;

	int totalR = 0, totalB = 0;

	for (int i = 0; i < n; i++) {
		if (ball[i] == 'R') {
			totalR++;
		}
		else {
			totalB++;
		}
	}

	int ans = min(totalR, totalB);

	int left = 1;

	for (int i = 1; i < n; i++) {
		if (ball[0] != ball[i]) {
			break;
		}
		left++;
	}

	if (ball[0] == 'R') {
		ans = min(totalR - left, ans);
	}
	else {
		ans = min(totalB - left, ans);
	}

	int right = 1;

	for (int i = n - 2; i >= 0; i--) {
		if (ball[n - 1] != ball[i]) {
			break;
		}
		right++;
	}

	if (ball[n - 1] == 'R') {
		ans = min(totalR - right, ans);
	}
	else {
		ans = min(totalB - right, ans);
	}

	cout << ans;

	return 0;

}
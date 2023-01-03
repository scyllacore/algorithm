#include <iostream>

using namespace std;

#define MAX 500000+1

int top[MAX] = { 0 }, bottom[MAX] = { 0 };

int main() {

	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	int n, h;
	cin >> n >> h;

	int i, inH;
	for (i = 0; i < n; i ++) {
		cin >> inH;

		if (i % 2)top[h - inH + 1]++;
		else bottom[inH]++;
	}

	for (i = 1; i <= h; i++) {
		bottom[h - i] += bottom[h - i + 1];
		top[i] += top[i - 1];
	}

	int ansBreak = n;
	int ansCnt = 1;

	for (i = 1; i <= h; i++) {
		if (bottom[i] + top[i] < ansBreak) {
			ansBreak = bottom[i] + top[i];
			ansCnt = 1;
		}
		else if (bottom[i] + top[i] == ansBreak) {
			ansCnt++;
		}
	}

	cout << ansBreak << ' ' << ansCnt;
	return 0;

}
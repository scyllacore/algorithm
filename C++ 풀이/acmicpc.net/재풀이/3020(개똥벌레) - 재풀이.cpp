#include <iostream>
#include <vector>	

using namespace std;

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	int n, h;
	cin >> n >> h;

	vector<int> aVec(h + 1, 0), bVec(h + 1, 0);

	int a, b;

	for (int i = 1; i <= n / 2; i++) {
		cin >> a;
		aVec[a]++;
		cin >> b;
		bVec[h - b + 1]++;
	}

	for (int i = 1; i <= h; i++) {
		aVec[h - i] += aVec[h - i + 1];
		bVec[i] += bVec[i - 1];
	}

	int ansVal = n, ansCnt = 0;

	for (int i = 1; i <= h; i++) {
		if (aVec[i] + bVec[i] < ansVal) {
			ansVal = aVec[i] + bVec[i];
		}
	}

	for (int i = 1; i <= h; i++) {
		if (aVec[i] + bVec[i] == ansVal) {
			ansCnt++;
		}
	}

	cout << ansVal << ' ' << ansCnt;

	return 0;
}
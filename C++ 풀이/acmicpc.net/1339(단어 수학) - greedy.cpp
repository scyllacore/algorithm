#include <iostream>
#include <functional>
#include <algorithm>

using namespace std;


int main() {

	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	int n, i, j;
	cin >> n;

	string word[10];
	int alpha[26] = { 0 };

	for (i = 0; i < n; i++) {
		cin >> word[i];
	}

	int tmpPow;

	for (i = 0; i < n; i++) {
		tmpPow = 1;
		for (j = word[i].size()-1; j >= 0; j--) {
			alpha[word[i][j] - 'A'] += tmpPow;
			tmpPow *= 10;
		}
	}

	sort(alpha, alpha + 26, greater<>());

	int res = 0;

	for (i = 0; i < 10; i++) {
		res += alpha[i] * (9 - i);
	}

	cout << res;

	return 0;
}
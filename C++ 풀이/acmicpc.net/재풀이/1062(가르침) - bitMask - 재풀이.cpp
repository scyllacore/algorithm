#include <iostream>
#include <algorithm>

using namespace std;

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	int i, j;

	int n, k;
	cin >> n >> k;

	if(k < 5){
		cout << 0;
		return 0;
	}

	int* words = new int[n] {0};
	string str;

	for (i = 0; i < n; i++) {
		cin >> str;

		for (j = 4; j < str.length() - 4; j++) {
			words[i] |= 1 << (str[j] - 'a');
		}
	}


	int alphaCheck = 0;
	alphaCheck |= 1 << ('a' - 'a');
	alphaCheck |= 1 << ('c' - 'a');
	alphaCheck |= 1 << ('i' - 'a');
	alphaCheck |= 1 << ('n' - 'a');
	alphaCheck |= 1 << ('t' - 'a');

	int answer = 0;

	for (int bitCase = alphaCheck; bitCase < (1 << 26); bitCase++) {

		if (alphaCheck != (bitCase & alphaCheck)) {
			continue;
		}

		int alphaCnt = 0;

		for (i = 0; i < 26; i++) {
			if (bitCase & (1 << i)) {
				alphaCnt++;
			}
		}

		if (alphaCnt != k) {
			continue;
		}

		int readingWord = 0;

		for (i = 0; i < n; i++) {
			if (words[i] == (bitCase & words[i])) {
				readingWord++;
			}
		}

		answer = max(readingWord, answer);
	}

	cout << answer;
	return 0;
}
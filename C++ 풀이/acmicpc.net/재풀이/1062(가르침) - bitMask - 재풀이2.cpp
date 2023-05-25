#include <iostream>
#include <algorithm>

using namespace std;

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	int n, k;
	cin >> n >> k;
	int* words = new int[n] {0};
	string word;

	/*for (int i = 0; i < n; i++) {
		cin >> words[i];
	}*/

	for (int i = 0; i < n; i++) {
		cin >> word; //단어도 비트마스크로 처리해준다.

		for (int j = 4; j < word.length() - 4; j++) {
			words[i] |= (1 << (word[j] - 'a'));
		}

	}

	int alphaCase = 0;

	alphaCase |= (1 << ('a' - 'a'));
	alphaCase |= (1 << ('c' - 'a'));
	alphaCase |= (1 << ('i' - 'a'));
	alphaCase |= (1 << ('n' - 'a'));
	alphaCase |= (1 << ('t' - 'a'));

	int maxCnt = 0;

	for (int bitCase = alphaCase; bitCase < (1 << 26); bitCase++) {

		if ((alphaCase & bitCase) != alphaCase) {
			continue;
		}

		int alphaCnt = 0;

		for (int i = 0; i < 26; i++) {
			if (bitCase & (1 << i)) {
				alphaCnt++;
			}
		}

		if (alphaCnt > k) {
			continue;
		}

		int wordCnt = 0;

		/*for (int i = 0; i < n; i++) {
			int length = words[i].length();
			alphaCnt = 0;

			for (int j = 4; j < length - 4; j++) {
				if (bitCase & (1 << (words[i][j] - 'a'))) {
					alphaCnt++;
				}
			}

			if (alphaCnt == length - 8) {
				wordCnt++;
			}

		}*/

		for (int i = 0; i < n; i++) {
			if ((words[i] & bitCase) == words[i]) { // bitCase가 words[i]를 포함하고 있다. (words[i] & bitCase) == bitCase 이거 헷갈림
				wordCnt++;
			}
		}

		maxCnt = max(wordCnt, maxCnt);

	}

	cout << maxCnt;
	return 0;
}
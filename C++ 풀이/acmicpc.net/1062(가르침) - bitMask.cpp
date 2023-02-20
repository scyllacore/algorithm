#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	int visited = 0;
	int n, k;


	cin >> n >> k;

	vector<string> words(n);

	int i, j;

	for (i = 0; i < n; i++) {
		cin >> words[i];
	}

	if (k < 5) {
		cout << 0;
		return 0;
	}
	if (k > 25) {
		cout << n;
		return 0;
	}

	visited |= (1 << ('a' - 'a'));
	visited |= (1 << ('c' - 'a'));
	visited |= (1 << ('i' - 'a'));
	visited |= (1 << ('n' - 'a'));
	visited |= (1 << ('t' - 'a'));

	vector<int> wordBit(n, 0);

	for (i = 0; i < n; i++) {
		string word = words[i];

		for (j = 4; j < word.size() - 4; j++) {
			wordBit[i] |= (1 << (word[j] - 'a'));
		}
	}

	int answer = 0;

	for (i = visited; i < (1 << 26); i++) {

		if ((i & visited) != visited) {
			continue;
		}

		int bitCnt = 0;

		for (j = 0; j < 26; j++) {
			if (i & (1 << j)) {
				bitCnt++;
			}
		}

		if (bitCnt == k) {
			int maxCnt = 0;

			for (j = 0; j < n; j++) {
				if (wordBit[j] == (i & wordBit[j])) {
					maxCnt++;
				}
			}

			answer = max(maxCnt, answer);
		}
	}

	cout << answer;

	return 0;

}
#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

unordered_map<string, int> countWord;

bool cmp(const string& w1, string& w2) {
	if (countWord[w1] != countWord[w2]) {
		return countWord[w1] > countWord[w2];
	}

	if (w1.length() != w2.length()) {
		return w1.length() > w2.length();
	}

	return w1.compare(w2) < 0;

}

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	int n, m;
	cin >> n >> m;

	vector<string> words;

	string word;

	for (int i = 0; i < n; i++) {
		cin >> word;

		if (word.length() < m) {
			continue;
		}

		if (countWord[word] == 0) {
			words.push_back(word);
		}

		countWord[word]++; //실수1. 이 라인을 if문 가운데 두면 안 된다.

	}

	sort(words.begin(), words.end(), cmp);

	for (string w : words) {
		cout << w << '\n';
	}

	return 0;
}
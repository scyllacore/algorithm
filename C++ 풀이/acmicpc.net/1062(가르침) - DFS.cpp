#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool visited[26] = { 0 };
int n, k;
vector<string> words;

int maxCnt = 0;

int countWord(string word) {
	for (int i = 0; i < word.size(); i++) {
		if (!visited[word[i] - 'a']) {
			return 0;
		}
	}

	return 1;
}

void dfs(int start, int depth) {
	if (depth >= k - 5) {

		int cnt = 0;

		for (string word : words) {
			cnt += countWord(word);
		}

		maxCnt = max(cnt, maxCnt);
		return;
	}

	for (int i = start; i < 26; i++) {
		if (visited[i]) {
			continue;
		}

		visited[i] = 1;
		dfs(i + 1, depth + 1);
		visited[i] = 0;
	}

}

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> n >> k;

	words.assign(n, "");

	for (int i = 0; i < n; i++) {
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

	visited['a' - 'a'] = 1;
	visited['c' - 'a'] = 1;
	visited['i' - 'a'] = 1;
	visited['n' - 'a'] = 1;
	visited['t' - 'a'] = 1;

	dfs(0, 0);

	cout << maxCnt;

	return 0;

}
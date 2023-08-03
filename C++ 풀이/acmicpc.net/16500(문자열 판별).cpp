#include <iostream>
#include <vector>

using namespace std;

#define SIZE 100

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	string str;
	cin >> str;

	int n;
	cin >> n;

	vector<string> words(n);

	for (int i = 0; i < n; i++) {
		cin >> words[i];
	}

	bool dp[SIZE + 1] = { 0 };

	int strLen = str.length();
	dp[strLen] = 1;

	for (int i = strLen; i >= 0; i--) {
		for (int j = 0; j < n; j++) {
			if (str.find(words[j], i) == i && dp[i + words[j].length()]) {
				dp[i] = 1;
				break;
			}
		}
	}

	cout << dp[0];
	return 0;
}

/*
#include <iostream>
#include <unordered_set>
#include <queue>

using namespace std;

unordered_set<string> wordSet;

bool bfs(string& str) {
	queue<string> bfsQ;
	bfsQ.push(str);

	for (; !bfsQ.empty();) {

		string curStr = bfsQ.front();
		bfsQ.pop();

		for (int i = 1; i <= curStr.length(); i++) {
			string subStr = curStr.substr(0, i);

			if (wordSet.find(subStr) != wordSet.end()) {
				if (i == curStr.length()) {
					return 1;
				}

				subStr = curStr.substr(i);
				bfsQ.push(subStr);
			}
		}
	}

	return 0;
}

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	string str;
	cin >> str;

	int n;
	cin >> n;

	string word;

	for (int i = 0; i < n; i++) {
		cin >> word;
		wordSet.insert(word);
	}

	cout << bfs(str);

	return 0;
}
*/

/*
#include <iostream>
#include <unordered_set>

using namespace std;

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	string str;
	cin >> str;

	int n;
	cin >> n;

	string word;
	unordered_set<string> wordSet;

	for (int i = 0; i < n; i++) {
		cin >> word;
		wordSet.insert(word);
	}

	int start = 0;

	for (int end = 1; end <= str.length(); end++) {
		string subStr = str.substr(start, end - start);

		//cout << subStr << ' ' << start << ' ' << end << '\n';

		if (wordSet.find(subStr) != wordSet.end()) {
			start = end;
		}
	}

	cout << (start == str.length() ? 1 : 0);

	return 0;
}
*/
#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

bool bfs(string& s, string& t) {
	queue<string> bfsQ;
	bfsQ.push(t);

	int curLen;

	for (; !bfsQ.empty();) {
		string curWord = bfsQ.front();
		bfsQ.pop();

		if (!curWord.compare(s)) {
			return 1;
		}

		curLen = curWord.length();
		string newWord;

		if (curLen >= 2 && curWord[0] == 'B') { // B를 추가한 경우
			newWord = curWord.substr(1);
			reverse(newWord.begin(), newWord.end());
			bfsQ.push(newWord);
		}

		if (curLen >= 2 && curWord[curLen - 1] == 'A') { // A를 추가한 경우
			newWord = curWord.substr(0, curLen - 1);
			bfsQ.push(newWord);
		}
	}

	return 0;
}

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	string s, t;

	cin >> s >> t;

	cout << bfs(s, t);
	return 0;
}
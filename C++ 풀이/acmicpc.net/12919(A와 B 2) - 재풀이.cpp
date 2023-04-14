#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

bool bfs(string& s, string& t) {

	queue<string> bfsQ;
	bfsQ.push(t);

	for (; !bfsQ.empty();) {
		string curT = bfsQ.front();
		int curTLen = curT.length();
		bfsQ.pop();

		if (curT == s) {
			return 1;
		}

		string newT;

		if (curTLen >= 2 && curT[0] == 'B') {
			newT = curT.substr(1);
			reverse(newT.begin(), newT.end());
			bfsQ.push(newT);
		}
		if (curTLen >= 2 && curT[curTLen - 1] == 'A') {
			newT = curT.substr(0, curTLen - 1);
			bfsQ.push(newT);
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
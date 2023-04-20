#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

bool bfs(string& S, string& T) {

	queue<string> bfsQ;
	bfsQ.push(T);

	for (; !bfsQ.empty();) {

		string curT = bfsQ.front();
		bfsQ.pop();

		if (curT == S) {
			return 1;
		}

		int len = curT.length();

		if (len >= 2 && curT[len - 1] == 'A') {
			bfsQ.push(curT.substr(0, len - 1));
		}
		else if (len >= 2 && curT[len - 1] == 'B') {
			reverse(curT.begin(), curT.end());
			bfsQ.push(curT.substr(1));
		}
	}

	return 0;
}

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	string S, T;
	cin >> S >> T;

	cout << bfs(S, T);

	return 0;
}
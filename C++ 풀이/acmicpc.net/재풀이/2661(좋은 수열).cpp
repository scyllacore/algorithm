#include <iostream>
#include <string>

using namespace std;

int n;
string ans = "";

bool dfs(string str) {

	int len = str.length();

	for (int i = 1; i <= len / 2; i++) {
		string front = str.substr(len - 2 * i, i);
		string back = str.substr(len - i, i);

		if (front == back) {
			return 0;
		}
	}

	if (len >= n) {
		ans = str;
		return 1;
	}

	for (int i = 1; i <= 3; i++) {
		if (dfs(str + to_string(i))) {
			return 1;
		}
	}

	return 0;
}

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> n;

	dfs("");

	cout << ans;
	return 0;
}
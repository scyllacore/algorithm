#include <iostream>
#include <stack>
#include <string>

using namespace std;

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	int n, i;

	cin >> n;
	cin.ignore();
	string str;
	stack<char> revStack;

	while (n--) {

		string revStr = "";
		getline(cin, str);

		for (i = 0; i < str.length(); i++) {

			if (str[i] != ' ') {
				revStack.push(str[i]);
			}
			else {
				while (!revStack.empty()) {
					revStr += revStack.top();
					revStack.pop();
				}
				revStr += ' ';
			}

		}

		while (!revStack.empty()) {
			revStr += revStack.top();
			revStack.pop();
		}

		cout << revStr << '\n';
	}

	return 0;
}
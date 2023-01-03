#include <iostream>
#include <string>
#include <stack>

using namespace std;

int main() {

	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	string str;

	for (;;) {

		getline(cin, str);

		if (str[0] == '.') { break; }

		stack<char> Brackets;

		for (string::iterator ch = str.begin(); ch < str.end(); ch++) {
			if (*ch == '(' || *ch == '[') { Brackets.push(*ch); }
			else if (*ch == ')') {
				if (!Brackets.empty() && Brackets.top() == '(') { Brackets.pop(); }
				else { Brackets.push(')'); }
			}
			else if (*ch == ']') {
				if (!Brackets.empty() && Brackets.top() == '[') { Brackets.pop(); }
				else { Brackets.push(']'); }
			}
			
		}

		if (Brackets.empty()) {
			cout << "yes\n";
		}
		else {
			cout << "no\n";
		}

	}

	return 0;

}

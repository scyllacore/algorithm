#include <iostream>
#include <cstdbool>
#include <string>
#include <stack>
#include <queue>

using namespace std;

void revOut(stack<char>& revWord)
{


	while (!revWord.empty())
	{
		cout << revWord.top();
		revWord.pop();
	}



}


void fwdOut(queue<char>& fwdWord) {

	while (!fwdWord.empty())
	{
		cout << fwdWord.front();
		fwdWord.pop();
	}
}



int main() {

	cin.tie(NULL);
	ios::sync_with_stdio(false);

	string str;
	stack<char> revWord;
	queue<char> fwdWord;

	int i;
	bool flag = 0;

	getline(cin, str);

	int len = str.length();

	for (i = 0; i < len; i++)
	{
		if (str.at(i) == '<') {
			revOut(revWord);

			for (; str.at(i) != '>'; i++) { fwdWord.push(str.at(i)); }
			fwdWord.push('>');

			fwdOut(fwdWord);
		}
		else {
			for (; i < len && str.at(i) != ' ' && str.at(i) != '<'; i++) { revWord.push(str.at(i)); }

			revOut(revWord);

			if (i >= len) { break; }

			if (str.at(i) == ' ') { cout << ' '; }
			else { i--; }
		}
	}
	revOut(revWord);

	return 0;
}


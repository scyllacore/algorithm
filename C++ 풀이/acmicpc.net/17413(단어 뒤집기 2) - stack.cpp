#include <iostream>
#include <string>
#include <stack>

using namespace std;

void revOut(stack<char>& revWord)
{

	while (!revWord.empty())
	{
		cout << revWord.top();
		revWord.pop();
	}

}

int main() {

	cin.tie(NULL);
	ios::sync_with_stdio(false);

	string str;
	stack<char> revWord;

	int i;
	bool flag = 0;

	getline(cin, str);

	for (i = 0; i < str.size(); i++)
	{
		if (str[i] == '<') {
			revOut(revWord);
			cout << '<';
			for (; str[++i] != '>'; ) { cout << str[i]; }
			cout << '>';
		}
		else {
			if (str[i] == ' ') {
				revOut(revWord);
				cout << ' ';
			}
			else {
				revWord.push(str[i]);
			}
		}
	}

	revOut(revWord);

	return 0;
}


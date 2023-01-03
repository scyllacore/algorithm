#include <iostream>
#include <stack>

using namespace std;

int main() {

	cin.tie(NULL);
	ios::sync_with_stdio(false);

	string str;
	int n,i;
	char cmd, ch;

	stack<char> left, right;

	cin >> str >> n;

	for (i = 0; i < str.size(); i++)
	{
		left.push(str.at(i));
	}

	i = n;

	while (i--)
	{
		cin >> cmd;

		if (cmd == 'L' && !left.empty()) 
		{
			right.push(left.top());
			left.pop();
		}
		else if (cmd == 'D' && !right.empty())
		{
			left.push(right.top());
			right.pop();
		}
		else if (cmd == 'B' && !left.empty())
		{
			left.pop();
		}
		else if (cmd == 'P')
		{
			cin >> ch;
			left.push(ch);
		}

	}

	while (!left.empty())
	{
		right.push(left.top());
		left.pop();
	}
	while (!right.empty())
	{
		cout << right.top();
		right.pop();
	}
//혼자 다시 푼 버전

}

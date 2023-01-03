#include <iostream>
#include <stack>

using namespace std;

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int n, i;
	cin >> n;


	for (i = 0; i < n; i++)
	{
		string str;
		stack<char> VPS;
		//string::iterator ptr;

		cin >> str;

		for (auto iter = str.begin(); iter != str.end(); iter++)
		{
			if (*iter == ')')
			{
				if (!VPS.empty() && VPS.top() == '(')
				{
					VPS.pop();
					continue;
				}
			}

			VPS.push(*iter);

		}
		cout << (VPS.empty() ? "YES" : "NO") << '\n';
	}




}
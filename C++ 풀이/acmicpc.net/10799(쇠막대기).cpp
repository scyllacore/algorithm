#include <iostream>
#include <stack>

using namespace std;

int main() {

	cin.tie(NULL);
	ios::sync_with_stdio(false);

	string ironBar;
	stack<char> barStack;
	int i,cnt=0;

	cin >> ironBar;

	for (i = 0; i < ironBar.size(); i++)
	{
		if (ironBar.at(i) == '(')
		{
			barStack.push('(');
		}
		else {
			barStack.pop();
			if (ironBar.at(i - 1) == '(') {
				cnt += barStack.size();
			}
			else {
				cnt += 1;
			}

		}

	}

	cout << cnt;


}
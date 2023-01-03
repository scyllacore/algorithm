#include <iostream>
#include <stack>

using namespace std;

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	string postFix,inFix;
	stack<char> optStk;
	char ch;

	cin >> postFix;

	for (int i = 0; i < postFix.size(); i++)
	{
		ch = postFix.at(i);

		if (ch >= 65 && ch <= 90) {
			inFix += ch;
			continue;
		}
		
		if (ch == '(')
		{
			optStk.push(ch);
			continue;
		}
		else if(ch == ')'){
			while (!optStk.empty() && optStk.top() != '(')
			{
				inFix += optStk.top();
				optStk.pop();
			}
			optStk.pop();
			continue;
		}

		if (ch == '*' || ch == '/') // A+B*C 이고 ch=*일 때 top이 +임으로 +를 스택에 남겨둔다 , top이 *인 경우 우선적으로 처리해야한다.
		{
			while (!optStk.empty() && (optStk.top() == '*' || optStk.top() == '/'))
			{
				inFix += optStk.top();
				optStk.pop();
			}
		}
		else {
			while (!optStk.empty() && optStk.top() != '(') // 위에서 우선순위에 따라 *,/는 처리 되었거나 스택 윗 부분에 쌓여있음으로 쭉 빼주면 된다
			{
				inFix += optStk.top();
				optStk.pop();
			}
		}

		optStk.push(ch);

	}

	while (!optStk.empty())
	{
		inFix += optStk.top();
		optStk.pop();
	}


	cout << inFix;
	return 0;

}

//순차적으로 맞춰 나가기
// A+B*C+D
// A/(B*(C+D)-E)
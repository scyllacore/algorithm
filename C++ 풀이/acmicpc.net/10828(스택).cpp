#include <iostream>

using namespace std;

int* stack;
int top = -1;

void push(int X)
{
	stack[++top] = X;
}

int pop() {
	return stack[top--];
}


int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int n,i,X;
	string inputStr;


	cin >> n;

	stack = new int[n];

	for (i = 0; i < n; i++)
	{
		cin >> inputStr;
		if (inputStr.compare("push") == 0)
		{
			cin >> X;
			push(X);
		}
		else if (inputStr.compare("pop") == 0)
		{
			if (top == -1)
			{
				cout << -1 << '\n';
				continue;	
			}
			cout << pop() << '\n';


		}
		else if (inputStr.compare("top") == 0)
		{
			if (top == -1)
			{
				cout << -1 << '\n';
				continue;
			}
			cout << stack[top] << '\n';
		}
		else if (inputStr.compare("size") == 0)
		{
			cout << top + 1 << '\n';
		}
		else if (inputStr.compare("empty") == 0)
		{
			if (top == -1)
			{
				cout << 1 << '\n';
				continue;
			}
			cout << 0 << '\n';
		}
	}

	//명령어가 첫 글자가 다 다름으로 inputStr[0] == 't' 이런식으로도 할 수 있을 듯 


}
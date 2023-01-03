#include <iostream>
#include <stack>

using namespace std;

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int n, i;
	cin >> n;

	int* num = new int[n];
	stack<int> stackNum;
	int cnt = 0;
	string outputStr;


	for (i = 0; i < n; i++)
	{
		cin >> num[i];
	}


	for (i = 1; i <= n; i++)
	{
		stackNum.push(i);
		outputStr += "+\n";


		for (; !stackNum.empty() && stackNum.top() == num[cnt]; cnt++) {
			stackNum.pop();
			outputStr += "-\n";
		}

	}

	if (!stackNum.empty())
	{
		cout << "NO";
	}
	else {
		//outputStr[outputStr.size() - 1] = '\0';
		cout << outputStr;
	}

	return 0;




}

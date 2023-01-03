#include <iostream>
#include <stack>

using namespace std;

int main()
{
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	int a, b,m;
	int sum = 0, i,n;
	stack<int> base;

	cin >> a >> b;
	cin >> m;

	for (i = 0; i < m; i++)
	{
		cin >> n;
		sum = sum * a + n;
	}

	for (; sum > 0;)
	{
		base.push(sum % b);
		sum /= b;
	}

	for (; !base.empty();)
	{
		cout << base.top() << ' ';
		base.pop();
	}

	return 0;
}
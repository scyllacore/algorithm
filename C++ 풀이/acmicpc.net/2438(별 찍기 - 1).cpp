#include <iostream>

using namespace std;

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int num, i, j;

	cin >> num;

	for (i = 1; i <= num; i++)
	{
		for (j = 0; j < i; j++)
		{
			cout << '*';
		}
		cout << '\n';
	}
	return 0;

}
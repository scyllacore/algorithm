#include <iostream>

using namespace std;

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);


	int n,i,sum=0;
	cin >> n;

	char* str = new char[n+1];


	cin >> str;

	for (i = 0; i < n; i++)
	{
		sum += str[i] - '0';
	}


	cout << sum;

	return 0;
}
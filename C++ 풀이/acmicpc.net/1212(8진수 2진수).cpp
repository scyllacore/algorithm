#include <iostream>

using namespace std;


void binary(int n,int cnt)
{
	if (cnt > 3) {
		return;
	}

	
	binary(n / 2, cnt + 1);
	cout << n % 2;
	
}


void binaryFirst(int n)
{
	if (n==0) {
		return;
	}


	binaryFirst(n / 2);
	cout << n % 2;

}

using namespace std;

int main()
{
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	string octal;
	cin >> octal;

	int i;
	
	if (octal[0] == '0')
	{
		cout << 0;
		return 0;
	}

	binaryFirst(octal[0] - 48);
	
	for (i = 1; i < octal.size(); i++)
	{
		binary(octal[i] - 48,1);
	}

}
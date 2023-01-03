#include <iostream>

using namespace std;

long long fpow(long long x, long long y)
{
	if (y <= 0)
	{
		return 1;
	}


	if (y % 2 == 0)
	{
		return fpow(x, y / 2) * fpow(x, y / 2);
	}
	else
	{
		return fpow(x, y / 2) * fpow(x, y / 2) * x;
	}


}


int main()
{
	//cin.tie(NULL);
	//ios::sync_with_stdio(false);

	long long x, y;
	cin >> x >> y;

	cout << fpow(x, y);



}
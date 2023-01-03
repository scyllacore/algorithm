#include <iostream>
#define MOD 20091024

using namespace std;

long long fpow(long long x, long long y)
{
	if (y <= 0)
	{
		return 1;
	}

	if (y % 2 == 0)
	{
		long long powTmp = fpow(x, y / 2) % MOD;
		return (powTmp * powTmp) % MOD;
	}
	else
	{
		return fpow(x, y  - 1) * x % MOD ;
	}


}


int main()
{
	//cin.tie(NULL);
	//ios::sync_with_stdio(false);

	long long x, y;
	cin >> x >> y;

	cout << fpow(x, y)%MOD;



}
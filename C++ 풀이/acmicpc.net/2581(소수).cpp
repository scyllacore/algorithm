#include <iostream>
#include <cstdbool>

using namespace std;

bool prime(int num)
{

	if (num == 1)
	{
		return false;
	}

	for (int i = 2; i * i <= num; i++)
	{
		if (num % i == 0)
			return false;
	}
	return true;

}


int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int n, m, sum = 0, i,min=0;


	cin >> n >> m;

	for (i = n; i <= m; i++)
	{
		if (prime(i))
		{
			sum += i;
			min = i++;
			break;
		}

	}

	for (; i <= m; i++)
	{
		if (prime(i))
		{
			sum += i;
		}
	}

	if (sum == 0)
	{
		cout << -1;
	}
	else {
		cout << sum << '\n';
		cout << min;
	}


}
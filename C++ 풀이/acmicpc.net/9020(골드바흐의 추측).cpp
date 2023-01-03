#include <iostream>
#include <cstdbool>
#include <vector>

using namespace std;

void isPrime(vector<bool>& prime)
{
	int i, j;
	int n = prime.size() - 1;

	prime[0] = prime[1] = true;

	for (i = 2; i * i <= n; i++)
	{
		if (prime[i] == false)
		{
			for (j = i * i; j <= n; j += i)
			{
				prime[j] = true;
			}
		}
	}


}

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int n, num, i, j;

	vector<bool> prime(10001, false);
	isPrime(prime);

	cin >> n;

	for (i = 0; i < n; i++)
	{
		cin >> num;

		for (j = num / 2; j > 0; j--)
		{
			if (prime[j] == 0 && prime[num - j] == 0)
			{
				cout << j << ' ' << num - j << '\n';
				break;
			}
		}


	}

}
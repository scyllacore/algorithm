#include <iostream>
#include <cstdbool>
#include <vector>

using namespace std;


void isPrime(vector<bool>& prime) {

	int i, j;
	int n = prime.size()-1;

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

	int i,j,n,max=0;
	vector<int> arr;

	for (;;)
	{
		cin >> n;

		if (n == 0)
			break;

		arr.push_back(n);

		if (n > max)
		{
			max = n;
		}

	}

	vector<bool> prime(2*max+1,false);
	isPrime(prime);

	for (i = 0; i < arr.size(); i++)
	{
		int cnt = 0;
		for (j = arr[i]+1; j <= 2 * arr[i]; j++)
		{
			if (prime[j] == false)
				cnt++;
		}
		cout << cnt << '\n';
	}

}
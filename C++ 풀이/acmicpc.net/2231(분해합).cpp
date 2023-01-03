#include <iostream>

using namespace std;

int main() {

	cin.tie(NULL);
	ios::sync_with_stdio(false);


	int n,i;
	int Nnum, sum,digit=0;


	cin >> n;

	int tmp = n;
	for (; tmp > 0;)
	{
		tmp /= 10;
		digit++;
	}


	int start = n - digit * 9;


	for (i=start; i<= n; i++)
	{
		Nnum = i,sum=i;

		for (; Nnum > 0;)
		{
			sum += Nnum % 10;
			Nnum /= 10;
		}

	
		if (sum == n)
		{
			cout << i;
			return 0;
		}
	}


	cout << 0;

}
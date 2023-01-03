#include <iostream>

using namespace std;

int main()
{
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	int n, intFac = 2;

	cin >> n;

	for (; n > 1 && intFac*intFac <=n;)
	{
		for (; n % intFac == 0;)
		{
			cout << intFac << '\n';
			n /= intFac;
			//cout << n << '\n';
		}
		intFac++;
	}

	if (n > 1)
	{
		cout << n;
	}


	return 0;


}
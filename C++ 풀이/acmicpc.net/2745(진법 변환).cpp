#include <iostream>

using namespace std;

int main()
{
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	string radix;
	int sum = 0, b,i;
	int num=0;

	cin >> radix >> b;

	for (i = 0; i < radix.size(); i++)
	{
		if (radix[i] >= 48 && radix[i] <= 57)
		{
			num = radix[i] - 48;
		}
		else if (radix[i] >= 65 && radix[i] <= 90)
		{
			num = radix[i] - 55;
		}

		sum = sum * b + num;
	}

	cout << sum;

	return 0;


}
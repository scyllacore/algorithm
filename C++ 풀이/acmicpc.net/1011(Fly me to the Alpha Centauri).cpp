#include <iostream>
using namespace std;

int main()
{
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	int tc;
	cin >> tc;
	for (int i = 0; i < tc; i++)
	{
		long long x, y, len;
		cin >> x >> y;
		len = y - x;
		long long pos = 1,turn = 1,pos_pow = 0;

		while (pos < len)
		{
			pos_pow++;

			turn++;	pos += pos_pow;
			if (pos >= len)break;

			turn++; pos += pos_pow;
			if (pos >= len)break;
		}
		if (pos > len)turn--;
		cout << turn << '\n';
	}


	return 0;
}
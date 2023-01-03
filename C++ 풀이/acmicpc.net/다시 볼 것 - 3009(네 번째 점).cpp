#include <iostream>
#include <vector>

using namespace std;

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);


	int x,y,i;

	int cntX[1001] = { 0 }, cntY[1001] = { 0 };

	for (i = 0; i < 3; i++)
	{
		cin >> x >> y;

		cntX[x]++, cntY[y]++;
	}

	for (i = 0; i <=1000; i++)
	{
		if (cntX[i] == 1)
		{
			cout << i << ' ';
			break;
		}
	}

	for (i = 0; i <= 1000; i++)
	{
		if (cntY[i] == 1)
		{
			cout << i;
			break;
		}
	}



}
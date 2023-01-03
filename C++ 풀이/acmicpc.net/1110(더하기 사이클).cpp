#include <iostream>

using namespace std;

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int num,cnt=0,cycNum;

	cin >> num;

	cycNum = num;

	while (1)
	{
		cycNum = (cycNum % 10) * 10 + ((cycNum % 10) + (cycNum / 10))%10;
		cnt++;

		if (cycNum == num)
			break;
	}

	cout << cnt;

}
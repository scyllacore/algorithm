#include <iostream>

using namespace std;

int main()
{
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	string Binary;
	cin >> Binary;

	int i = 0;

	if (Binary.size() % 3 == 1)
	{
		cout << Binary[0]-48;
		i += 1;
	}
	else if (Binary.size() % 3 == 2)
	{
		cout << 2*(Binary[0]-48) + (Binary[1]-48);
		i += 2;
	}

	for (; i < Binary.size(); i+=3)
	{
		cout << 4 * (Binary[i]-48) + 2 * (Binary[i+1]-48) + (Binary[i+2]-48);
	}



}
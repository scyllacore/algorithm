#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	char strNum[20];
	int num[20] = { 0 };
	int i;

	cin >> strNum;

	int len = strlen(strNum);

	for (i = 0; i < len; i++)
	{
		num[i] = strNum[i] - 48;
	}

	sort(num, num + len,greater<>());
	
	for (i = 0; i < len; i++)
	{
		cout << num[i];
	}

}
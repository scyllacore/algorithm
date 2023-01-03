#include <iostream>

using namespace std;

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	string str;
	int alpha[26] = { 0 },i;

	cin >> str;

	for (i = 0; i < str.size(); i++)
	{
		alpha[str[i] - 97]++;
	}

	for (i = 0; i < 26; i++)
	{
		cout << alpha[i] << ' ';
	}

}
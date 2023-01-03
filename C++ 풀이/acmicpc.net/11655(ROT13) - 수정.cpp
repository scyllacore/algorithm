#include <iostream>
#include <cctype>
#include <string>

using namespace std;

int main()
{
	cin.tie(NULL), cout.tie(NULL);
	ios::sync_with_stdio(false);

	string str;
	int i, ROT13;

	getline(cin, str);

	for (i = 0; i < str.size(); i++)
	{
		if (islower(str[i])) {
			ROT13 = str[i] - 'a';
			str[i] = ((ROT13+13)%26)+'a';
		}
		else if (isupper(str[i])) {
			ROT13 = str[i] - 'A';
			str[i] = ((ROT13 + 13) % 26) + 'A';
		}
	}

	cout << str;

}
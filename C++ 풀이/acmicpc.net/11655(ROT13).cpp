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
			ROT13 = str[i] - 110;
			str[i] = (ROT13 < 0 ? 26 + ROT13 : ROT13) + 97; // -가 아니라 +이다.
		}
		else if (isupper(str[i])) {
			ROT13 = str[i] - 78;
			str[i] = (ROT13 < 0 ? 26 + ROT13 : ROT13) + 65;
		}
		//cout << (int)str[i] << ' ';
	}

	//cout << '\n';
	cout << str;

}
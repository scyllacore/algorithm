#include <iostream>

using namespace std;

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	string str;
	int alpha[26], i;

	fill_n(alpha, 26, -1);

	cin >> str;

	for (i = 0; i < str.size(); i++)
	{
		if (alpha[str[i] - 'a'] == -1) {
			alpha[str[i] - 'a'] = i;
		}
	}

	for (i = 0; i < 26; i++)
	{
		cout << alpha[i] << ' ';
	}

	return 0;


}
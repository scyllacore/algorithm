#include <iostream>

using namespace std;

int main() {

	cin.tie(NULL);
	ios::sync_with_stdio(false);


	char str[1000001];
	int alpha[26] = { 0 };


	cin >> str;

	int i,max=0,flag=0;

	for (i = 0; str[i] != '\0'; i++)
	{
		if (str[i] >= 97) {
			alpha[str[i] - 97]++;
		}
		else if(str[i] >= 65) {
			alpha[str[i] - 65]++;
		}
	}

	for (i = 0; i < 26; i++)
	{
		if (alpha[max] < alpha[i]) {
			max = i;
		}

	}

	for (i = 0; i < 26; i++)
	{
		if (alpha[max] == alpha[i]) {
			flag++;
		}

	}

	if (flag > 1)
	{
		cout << '?';
	}
	else {

		cout << (char)(65+max) ;
	}


	return 0;


}
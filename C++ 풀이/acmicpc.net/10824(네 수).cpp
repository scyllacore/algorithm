#include <iostream>
#include <string>

using namespace std;

int main() {

	cin.tie(NULL), cout.tie(NULL);
	ios::sync_with_stdio(false);

	string str;
	string num1Str, num2Str;
	int i;

	for (i = 0; i < 2; i++)
	{
		cin >> str;
		num1Str += str;
	}

	for (i = 0; i < 2; i++)
	{
		cin >> str;
		num2Str += str;
	}

	//cout << num1Str << ' ' << num2Str << '\n';


	unsigned long long num1=0, num2=0;

	for (i = 0; i < num1Str.size(); i++)
	{
		num1 = (num1 * 10) + (num1Str[i]-48);
	}

	for (i =0; i < num2Str.size(); i++)
	{
		num2 = num2 * 10 + (num2Str[i] - 48);
	}

	cout << num1 + num2;
	return 0;

}
#include <iostream>
#include <string>
#include <cctype>

using namespace std;

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	string str;
	int i,j;

	for (i = 0; i < 100; i++)
	{
		int arr[4] = { 0 };
		getline(cin,str);

		if (!(islower(str[0]) || isupper(str[0]) || isdigit(str[0]) || isspace(str[0])))
		{
			break;
		}

		for (j = 0; j < str.size(); j++)
		{
			if (islower(str[j])){
				arr[0]++;
			}
			else if (isupper(str[j])) {
				arr[1]++;
			}
			else if (isdigit(str[j])) {
				arr[2]++;
			}
			else if (isspace(str[j])) {
				arr[3]++;
			}
		}
		
		for (j = 0; j < 4; j++)
		{
			cout << arr[j] << ' ';
		}
		cout << '\n';


	}


}
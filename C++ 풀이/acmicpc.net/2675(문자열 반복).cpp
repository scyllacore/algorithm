#include <iostream>

using namespace std;

int main() {

	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int n,i,j,k;
	cin >> n;

	for (i = 0; i < n; i++)
	{
		int loop;
		cin >> loop;

		char *str= new char[21];

		cin >> str;

		for (j = 0; str[j] != '\0'; j++) {
			for (k = 0; k < loop; k++) {
				cout << str[j];
			}
		}

		cout << '\n';

		delete[] str;


	}

	return 0;

}
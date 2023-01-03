#include <iostream>

using namespace std;

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int n, i, j, flag = 0, cnt = 0, sum = 0;
	cin >> n;

	char str[81];

	for (i = 0; i < n; i++)
	{
		cin >> str;

		for (j = 0; str[j] != '\0'; j++) // cstring - strlen 사용 안하고 풀 때
		{
			if (str[j] == 'O') {
				sum += ++cnt;
			}
			else if (str[j] == 'X') {
				cnt = 0;
			}
		}

		cout << sum << '\n';
		sum = 0, cnt = 0;

	}


	return 0;

}
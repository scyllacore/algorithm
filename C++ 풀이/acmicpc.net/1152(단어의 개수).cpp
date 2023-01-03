#include <iostream>

using namespace std;

#define MAX (int)1e7

char str[MAX];

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int i, cnt = 0;

	cin.getline(str, MAX);


	for (i = 0; str[i] != '\0'; i++)
	{
		if (str[i] >= 33 && str[i + 1] < 33)
			cnt++;

	}

	cout << cnt;
	return 0;


}
#include <iostream>

using namespace std;

int main() {

	cin.tie(NULL);
	ios::sync_with_stdio(false);


	int arr[10] = { 0 }, a, b, c, num, i;
	cin >> a >> b >> c;

	num = a * b * c;

	for (; num > 0;)
	{
		arr[num % 10]++;
		num /= 10;
	}

	for (i = 0; i < 10; i++)
	{
		cout << arr[i] << '\n';
	}

	return 0;


}
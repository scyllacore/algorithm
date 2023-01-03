#include <iostream>

using namespace std;


int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int n, test, i;

	int arr[41] = { 0,1 };

	for (i = 2; i < 41; i++)
	{
		arr[i] = arr[i - 1] + arr[i - 2];
	}


	cin >> n;

	for (i = 0; i < n; i++)
	{
		cin >> test;
		if (test == 0)
			cout << 1 << ' ' << 0 << '\n';
		else if (test == 1)
			cout << 0 << ' ' << 1 << '\n';
		else
			cout << arr[test - 1] << ' ' << arr[test] << '\n';
	}
}
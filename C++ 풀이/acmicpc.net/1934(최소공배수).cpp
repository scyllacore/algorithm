#include <iostream>

using namespace std;

int gcd(int x, int y)
{
	int tmp;

	while (y != 0) {
		tmp = x % y;
		x = y;
		y = tmp;
	}

	return x;

}

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	int n,n1,n2,i;
	cin >> n;

	for (i = 0; i < n; i++)
	{
		cin >> n1 >> n2;
		cout << (n1 * n2) / gcd(n1, n2) << '\n';
	}

}
#include <iostream>

using namespace std;

int gcd(int x, int y)
{
	int tmp;

	while (y!=0) {
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
	
	int n1, n2;
	cin >> n1 >> n2;

	cout << gcd(n1, n2) << '\n';
	cout << (n1*n2)/gcd(n1, n2);

}
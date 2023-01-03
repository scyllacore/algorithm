#include <iostream>
#include <cmath>

using namespace std;


void move(int from, int to)
{
	cout << from << ' ' << to << '\n';
}


void hanoi(int n, int from, int by, int to)
{
	if (n == 1)
	{
		move(from, to);
	}
	else
	{
		hanoi(n - 1, from, to, by);
		move(from, to);
		hanoi(n - 1, by, from, to);

	}

}

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int n;
	cin >> n;

	cout << (int)pow(2, n) - 1 << '\n';
	hanoi(n, 1, 2, 3);

}
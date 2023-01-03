#include <iostream>
#include <stack>

using namespace std;

char radix36[36];

void radixInitial() {
	int i, ch = 48;

	for (i = 0; i < 10; i++)
	{
		radix36[i] = ch++;
	}
	ch = 65;

	for (; i < 36; i++)
	{
		radix36[i] = ch++;
	}
}

int main()
{
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	radixInitial();

	int n, b;
	stack<char> radix;

	cin >> n >> b;


	for (; n > 0;)
	{
		radix.push(radix36[n % b]);
		n /= b;
	}


	for (; !radix.empty();)
	{
		cout << radix.top();
		radix.pop();
	}

	return 0;

}
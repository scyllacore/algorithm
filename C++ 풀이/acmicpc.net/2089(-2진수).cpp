#include <iostream>
#include <stack>
#include <cmath>

using namespace std;

int main() {

	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	int n;
	stack<int> binaryM;

	cin >> n;

	if (n == 0)
	{
		cout << 0;
		return 0;
	}

	while (n != 0) {
		binaryM.push(abs(n) % 2);
		if (n % 2 == 0)
		{
			n /= -2;
		}
		else {
			n = (n - 1) / (-2);
		}

	}

	for (; !binaryM.empty();)
	{
		cout << binaryM.top();
		binaryM.pop();
	}

	return 0;
}
//-13 = -2 * 7  1
//7 = -2 * -3  1
//- 3 = -2 * 2  1
//2 = -2 * -1  0
//- 1 = -2 * 1  1
//1 = -2 * 0  1

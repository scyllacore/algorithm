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
		binaryM.push(abs(n) % 2); // 음수,양수인지에 따라 절댓값이 같아도 나머지는 다르게 나올 수 있음.
		if (n % 2 == 0) // 홀짝을 구분할 때는 음수,양수 상관 없음.
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

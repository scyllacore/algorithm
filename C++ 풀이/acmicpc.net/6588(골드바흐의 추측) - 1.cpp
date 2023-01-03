#include <iostream>
#include <cstdbool>
#include <vector>

using namespace std;

bool prime[1000001] = { 1,1 };
vector<int> primeNum;
int n1, n2;

void primeCheck() {
	int i, j;

	for (i = 2; i * i <= 1000000; i++) {
		if (prime[i] == 0)
		{
			for (j = i * i; j <= 1000000; j += i)
			{
				prime[j] = 1;
			}
		}
	}
}

bool conjectureCheck(int n) {

	int i, front = 3, back = n - 3;
	// 짝수-홀수 = 홀수
	// front+back=n 임으로 front=3,back=n-3임.


	for (; front <= back;)
	{
		if (!prime[front] && !prime[back])
		{
			n1 = front;
			n2 = back;
			return 1;
		}

		front += 2; 
		back -= 2;//짝수는 소수가 아님으로 2씩 +,-하여 홀수만 확인한다.
	}

	return 0;

}


int main()
{
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	int n;

	primeCheck();

	for (;;)
	{
		cin >> n;

		if (n == 0) { break; }

		if (conjectureCheck(n)) {
			cout << n << " = " << n1 << " + " << n2 << '\n';
		}
		else {
			cout << "Goldbach's conjecture is wrong." << '\n';
		}

	}

	return 0;
}
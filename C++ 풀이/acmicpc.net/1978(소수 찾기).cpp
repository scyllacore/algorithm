#include <iostream>
#include <cstdbool>

using namespace std;

bool prime[1001]={1,1};

void primeCheck() {
	int i, j;
	for (i = 2; i * i <= 1000; i++) // 여긴 왜 i*i인지 모르겠다
	{
		if (prime[i] == 0) {
			for (j = i * i; j <= 1000; j += i)
			{
				prime[j] = 1;
			}
		}
	}
}

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	int n, num, i, cnt = 0;

	cin >> n;

	primeCheck();

	for (i = 0; i < n; i++)
	{
		cin >> num;

		if (prime[num] == 0)
		{
			cnt++;
		}
	}

	cout << cnt;
}

#include <iostream>

#define MAX (int)1e7
bool prime[MAX+1];

using namespace std;
int n1, n2;

void primeCheck() {
	int i, j;

	for (i = 2; i * i <= MAX; i++)
	{
		if (prime[i] == 0)
		{
			for (j = i * i; j <= MAX; j += i)
			{
				prime[j] = 1;
			}
		}

	}

}

int conjecture(int n) {

	if (n == 4)
	{
		return 1;
	}

	int front = 3, back = n - 3;
	int cnt = 0;

	for (; front <= back;)
	{
		if ((!prime[front] && !prime[back])) // && (front + back == n) 이건 필요 없음
		{
			//cout << front << ' ' << back << '\n';
			cnt++;
		}
		front += 2;
		back -= 2;

	}

	return cnt;
}


int main() {

	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	int n, i, num;

	cin >> n;

	primeCheck();

	for (i = 0; i < n; i++) {
		cin >> num;
		cout << conjecture(num) << '\n';
	}


}
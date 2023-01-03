#include <iostream>
#define N 10001

using namespace std;


int selfNum(int n) {

	int sum = n;

	while (!(n == 0))
	{
		sum += n % 10;
		n /= 10;

	}

	return sum;
}


int main()
{
	int i,idx;
	bool arr[N] = { 0 };

	for (i = 1; i < N; i++)
	{
		idx = selfNum(i);

		if (idx < N)
		{
			arr[idx] = true;
		}
	}

	for (i = 1; i < N; i++)
	{
		if (!arr[i])
		{
			cout << i << '\n';
		}
	}

	return 0;
}

//수열 공부 할 것
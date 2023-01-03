#include <stdio.h>
#include <stdbool.h>
#include <math.h>

bool IsPrime(int num);

int main(void)
{
	int num[5];

	for (int i = 0; i < 5; ++i)
		scanf("%d", &num[i]);

	for (int i = 0; i < 5; ++i)
	{
		// 입력 값이 1이면 소수 검사를 하지 않는다.
		if (num[i] == 1)
		{
			printf("number one\n");
			continue;
		}
		// 입력 값이 1 이외의 값이면 소수인지 검사를 한다.
		if (IsPrime(num[i]))
		{
			printf("prime number\n");
		}
		else
		{
			printf("composite number\n");
		}
	}
}

bool IsPrime(int num)
{
	// 2부터 num의 루트값 까지 진행하며 나눈다.
	// 이건 num = a * b 라면 작은 수로 나눠지면 큰 수로도 나눠지기 때문에
	// 작은 수 만 검사하는 것이다.
	for (int i = 2; i <= sqrt(num); i++) // i<= num/i
		if (num % i == 0)    return false;
	return true;
}

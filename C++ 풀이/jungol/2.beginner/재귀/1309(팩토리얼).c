#include <stdio.h>

long long factorial(long long n)
{
	if (n == 1) {// n이 1일 때
		printf("1! = 1\n");
		return 1;
	}    // 1을 반환하고 재귀호출을 끝냄

	printf("%d! = %d * %d!\n", n, n, n - 1);

	return n * factorial(n - 1);    // n과 factorial 함수에 n - 1을 넣어서 반환된 값을 곱함
}

int main()
{
	int n;

	scanf("%d", &n);

	printf("%lld", factorial(n));

	return 0;
}
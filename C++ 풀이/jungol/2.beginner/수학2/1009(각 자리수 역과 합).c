#include <stdio.h>
#pragma warning(disable: 4996) 

void an(int n);
int main(void)
{
	int n, sum;

	while (1)
	{
		scanf("%d", &n);

		if (n == 0)
			break;

		an(n);
	}
	return 0;
}
void an(int n)
{
	int sum = 0, a = 0, b = 0;

	while (1)
	{ //123
		a = (a * 10) + (n % 10); // 제일 뒷자리 수 구하기  3 -> 3*10+2 = 32 -> 32*10 + 1 = 321
		sum += n % 10; // 구한 뒷자리수 합치기 3 -> 5 -> 6
		n = n / 10; // 구한 뒷자리수 제외하고 나머지에 대해 12-> 1 -> 0 
		if (n == 0) // 끝
			break;
	}

	printf("%d %d\n", a, sum);

}

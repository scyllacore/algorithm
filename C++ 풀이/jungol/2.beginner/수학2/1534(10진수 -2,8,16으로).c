#include <stdio.h>

char nume[16] = { '0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'A', 'B', 'C', 'D', 'E', 'F' };

void change(int n, int b);

int main(void)
{
	int n, b;

	scanf("%d %d", &n, &b);

	change(n, b);


	return 0;
}

void change(int n, int b) //십진수 n을 b진수로 
{
	if (n != 0)
	{
		change(n / b, b);
		printf("%c", nume[n % b]);
	}

}

// 재귀 안쓰고 가능
// 10 -> 2진법 변환을 설명하며 나머지를 이용했을 때 변환된 진법 숫자를 알 수 있음을 설명
// 8, 16 등 다른 진법도 똑같은 원리인 것을 설명
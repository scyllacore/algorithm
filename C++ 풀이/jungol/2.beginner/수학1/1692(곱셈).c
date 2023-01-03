#include <stdio.h>


int main(void)
{
	// 자연수 2개를 저장할 배열
	int n[2];
	// 결과를 저장할 배열
	int result[4];
	int pow=1;

	for (int i = 0; i < 2; ++i)
		scanf_s("%d", &n[i]);

	// 곱셈 결과를 저장
	result[3] = n[0] * n[1];

	// 각 자리수 별 곱셈 결과 저장
	for (int i = 0; i < 3; ++i)
	{
		result[i] = n[0] * (n[1] % 10);
		result[i] *= pow;
		pow *= 10;
		n[1] /= 10;

	}

	printf("\n");

	// 결과를 출력한다.
	for (int i = 0; i < 3; ++i)
		printf("%6d+\n", result[i]);

	printf("-------\n");

	printf("%6d\n", result[3]);


}
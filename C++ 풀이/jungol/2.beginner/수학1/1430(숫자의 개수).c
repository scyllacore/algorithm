#include <stdio.h>

// 숫자를 세 줄 함수
void CountNumber(int mult, int result[]);

int main(void)
{
	// n: 입력 받을 변수, mult: 곱할 변수
	int n, mult = 1;
	// 결과를 0~9까지가 몇 번 나왔는지 저장할 배열
	int result[10];

	// 결과를 0으로 초기화 한다.
	for (int i = 0; i < 10; ++i)
		result[i] = 0;

	// 세번 입력 받으며 곱한다.
	for (int i = 0; i < 3; ++i)
	{
		//printf("%d번 입력 : ", i + 1);
		scanf("%d", &n);
		mult *= n;
	}

	//printf("\n곱셈값 : %d \n", mult);
	CountNumber(mult, result);
	//printf("\n");

	// 결과 출력
	//printf("갯수\n");
	for (int i = 0; i < 10; ++i)
		printf("%d\n", result[i]);
		//printf("%d : %d\n", i, result[i]);
}


// 숫자를 10으로 나눈 나머지(1의자리)의 숫자에 따라 배열의 값 증가
// 모든 자리를 확인하면 종료
void CountNumber(int mult, int result[])
{
	while (1)
	{
		result[mult % 10]++;
		mult /= 10;
		if (mult == 0)
			return;
	}
//재귀 안쓰고 푸는법
}

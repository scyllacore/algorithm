#include <stdio.h>


// 소수와 합성수를 표현
enum { PRIME = 0, COMPOSIT = 1 };

int Eratos(int* arr, int M, int N);

int main(void)
{

	int M, N;
	int* arr;
	scanf("%d %d", &M, &N);

	arr = (int *)malloc(sizeof(int)*N);

	for (int i = 0; i < N; ++i)
	{
		arr[i] = i + 1;
	}

	// 에라토스테네스의  체를 이용하여 개수를 구한다.
	printf("%d", Eratos(arr, M, N));

	free(arr);
}

int Eratos(int* arr, int M, int N)
{
	// 소수의 개수
	int cnt = 0;

	for (int i = 0; i < N; ++i)
	{
		// 합성수인 경우 제외함 + 1은 소수도 합성수도 아니니 제외
		if (arr[i] == COMPOSIT) continue;

		// 소수를 찾은 경우 범위 내에 있는 경우 개수 증가
		if (arr[i] >= M) cnt++;

		// 합성수가 아닌 가장 작은 수는 소수라고 판단
		// 배수를 판단하기 위해 현재 수를 저장
		int num = arr[i];
		arr[i] = PRIME;

		// 이 소수의 배수들은 합성수이므로 제외
		for (int j = i + num; j < N; j += num)
		{
			arr[j] = COMPOSIT;
		}
	}

	return cnt;
}

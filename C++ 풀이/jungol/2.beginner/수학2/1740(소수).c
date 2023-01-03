#include <stdio.h>
#include <math.h>

// 소수와 합성수를 표현
enum { PRIME = 0, COMPOSIT = 1 };

void Initialize(int arr[], int N);
void Eratos(int* arr, int M, int N, int* sum, int* min);
void PrintResult(int sum, int min);

int main(void)
{
	int* arr;
	int M, N;
	int sum, min;
	
	sum = min = 0;

	scanf("%d %d", &M, &N);

	arr = (int*)malloc(sizeof(int) * N);

	Initialize(arr, N);
	Eratos(arr, M, N, &sum, &min);
	PrintResult(sum, min);

	free(arr);
}

// 배열 값 초기화 함수
void Initialize(int arr[], int N)
{
	for (int i = 0; i < N; ++i)
	{
		arr[i] = i + 1;
	}
}

void Eratos(int* arr, int M, int N, int* sum1, int* min1)
{
	for (int i = 0; i < N; ++i)
	{
		// 합성수인 경우 제외함 + 1은 소수도 합성수도 아니니 제외
		if (arr[i] == COMPOSIT) continue;

		// 이 소수의 배수들은 합성수이므로 제외
		for (int j = i + arr[i]; j < N; j += arr[i])
		{
			arr[j] = COMPOSIT;
		}

		// 범위 안에 포함되는 경우 값을 더한다.
		// 그 중 처음 포함되는 것이 최소값이니 따로 저장한다.
		if (arr[i] < M) continue;
		if (arr[i] > N) continue;
		if (*min1 == 0)* min1 = arr[i];
		*sum1 += arr[i];
	}
}

// 결과를 출력한다.
void PrintResult(int sum, int min)
{
	if (min == 0)
	{
		//printf("false");
		printf("-1");
	}
	else
	{
		//printf("\nsum = %d\n", sum);
		//printf("min = %d\n", min);
		printf("%d\n", sum);
		printf("%d\n", min);
	}
}


//난 과정을 따로 다 분리했고
//이 풀이는 소수를 구하며 최솟값과 누적합을 다 같이 구하고 있음
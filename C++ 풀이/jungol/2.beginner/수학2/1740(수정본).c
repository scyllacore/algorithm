#include <stdio.h>

void getPrime(int arr[], int M, int N);
void SumMin(int arr[], int M, int N, int* sum, int* min);
void PrintResult(int sum, int min);


int main() {
	
	int *arr;
	int M, N;
	int sum, min;

	sum = min = 0;

	scanf("%d %d", &M, &N);

	arr = (int*)malloc(sizeof(int) * (N+1));

	getPrime(arr, M, N);
	SumMin(arr, M, N, &sum, &min);
	PrintResult(sum, min);
}

void getPrime(int arr[], int M, int N)
{
	int i, j;

	arr[0] = arr[1] = 0;

	for (i = 2; i <= N; ++i)
	{
		arr[i] = i + 1;
	}

	for (i = 2; i*i <= N; i++) {

		if (arr[i] == 0) // 이미 체크된 수의 배수는 확인하지 않는다

			continue;

		for (j = i + i; j <= N; j += i) { // i를 제외한 i의 배수들은 0으로 체크

			arr[j] = 0;
		}


	}

}


void SumMin(int arr[], int M, int N, int* sum, int* min)
{
	int i;

	for (i = M; i <= N; i++)
	{
		if (arr[i] > 1) {
			*min = i;
			break;
		}
	}

	for (i = M; i <= N; i++)
	{
		if (arr[i] > 1) {
			*sum += i;
		}
	}

}

void PrintResult(int sum, int min)
{
	if (min == 0)
	{
		printf("-1");
	}
	else
	{
		printf("%d\n", sum);
		printf("%d\n", min);
	}
}

//에라토스테네스의 체

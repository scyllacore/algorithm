#include <stdio.h>


// 소수와 합성수를 표현
int count(int* arr, int M, int N);
void Eratos(int* arr, int M, int N);

int main(void)
{

	int M, N;
	int *arr;
	scanf("%d %d", &M, &N);

	arr = (int*)malloc(sizeof(int) * (N+1));

	

	// 에라토스테네스의  체를 이용하여 개수를 구한다.
	Eratos(arr, M, N);

	printf("%d", count(arr, M, N));

	free(arr);
}

void Eratos(int *arr, int M, int N)
{
	// 소수의 개수
	int i,j;
	//arr[0] = arr[1] = 0;

	for (i = 2; i <= N; ++i)
	{
		arr[i] = i + 1;
	}



	for (i = 2; i * i <= N; i++) {

		if (arr[i] == 0) // 이미 체크된 수의 배수는 확인하지 않는다

			continue;

		for (j = i + i; j <= N; j += i) { // i를 제외한 i의 배수들은 0으로 체크

			arr[j] = 0;
		}


	}

}


int count(int *arr, int M, int N)
{
	int cnt = 0, i, j;

	for (i = M; i <= N; i++)
	{
		if (arr[i] > 1) {
			cnt++;
		}
	}


	return cnt;
}
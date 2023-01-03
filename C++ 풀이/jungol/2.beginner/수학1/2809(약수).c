#include <stdio.h>
#include <math.h>


/*
int main()
{
	int n, k;

	scanf("%d",&n);

	for (int i = 1; i <= n; i++)
	{
		if (n % i == 0)
			printf("%d ", i);

		}

	printf("\n");
	return 0;
}*/

int main()
{
	int N, i, j,tmp;
	int sq; // N의 제곱근을 저장하기 위해
	int arr[10000], cnt = 0; // N의 약수를 저장하기 위해
	scanf("%d", &N);

	sq = (int)sqrt(N); // N의 제곱근을 구하여 sq에 저장한다.

	for (i = 1; i <= sq; i++)
	{
		if (N % i == 0)
		{
			arr[cnt++] = i; // 작은수 저장
			if (N / i != i)
				arr[cnt++] = N / i; // 큰수 저장 (작은수와 같지 않을 경우) ,(1 3 3 9 x -> 1 3 9 똑같은 숫자는 하나만)
		}
	}

	for(i=0; i<cnt-1; i++)
		for(j=i+1; j<cnt; j++)
			if (arr[i] > arr[j])
			{
				tmp = arr[i];
				arr[i] = arr[j];
				arr[j] = tmp;

			}


	for (int i = 0; i < cnt; i++)
	{
		printf("%d ", arr[i]);
	}


}
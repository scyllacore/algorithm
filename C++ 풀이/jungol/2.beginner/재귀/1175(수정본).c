#include <stdio.h>

int nArr[8];
int N, M;

void print()
{
	int i,sum=0;

	for (i = 1; i <= N; i++)
		sum += nArr[i];

	if (sum == M)
	{
		for (i = 1; i <= N; i++)
			printf("%d ", nArr[i]);
		printf("\n");
	}

}

void sum_fuc(int k,int n)
{
	int i;

	if (!n)
	{
		print();
		return;
	}

	for (i = 1; i <= 6; i++)
	{
		nArr[k] = i;
		sum_fuc(k + 1,n - 1);
	}


}


int main()
{

	scanf("%d %d", &N, &M);

	sum_fuc(1,N);


}
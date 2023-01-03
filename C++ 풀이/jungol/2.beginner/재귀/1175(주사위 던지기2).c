#include  <stdio.h>

static int sum[10];
static int loc = 0;

void dice(int N, int M)
{
	for (int i = 1; i <= 6; ++i)
	{
		sum[loc] = i;

		if (loc == N - 1)
		{
			int total = 0;
			for (int j = 0; j <= loc; ++j)
				total += sum[j];

			if (total == M)
			{
				for (int k = 0; k < N; ++k)
					printf("%d", sum[k]);
				printf("\n");
			}
		}
		else
		{
			loc++;
			dice(N, M);
			loc--;
		}
	}
}

int main()
{
	int n, m;
	printf("n번 던져 합 m이 나올 경우의 수 n,m 입력 : ");
	scanf("%d %d", &n, &m);
	printf("\n");

	dice(n, m);

	return 0;
}

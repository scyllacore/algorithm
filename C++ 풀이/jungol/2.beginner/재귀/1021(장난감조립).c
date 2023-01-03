#include <stdio.h>
#pragma warning(disable:4996)

int ITEM[111][111] = { 0 };
int BASIC[111] = { 0 };
int N, M;

void make(int n)
{
	if (BASIC[n] != -1)
		BASIC[n] ++;

	else
	{
		for (int i = 1; i < N; ++i)
		{
			if (ITEM[n][i] != 0)
			{
				for (int j = 1; j <= ITEM[n][i]; ++j)
					make(i);
			}
		}
	}
}
int main()
{

	scanf("%d%d", &N, &M);
	for (int i = 1; i <= M; ++i)
	{
		int x, y, k;
		scanf("%d%d%d", &x, &y, &k);
		ITEM[x][y] = k;
		BASIC[x] = -1;
	}

	make(N);

	for (int i = 1; i < N; ++i)
	{
		if (BASIC[i] != -1)
			printf("%d %d\n", i, BASIC[i]);
	}

	return 0;
}
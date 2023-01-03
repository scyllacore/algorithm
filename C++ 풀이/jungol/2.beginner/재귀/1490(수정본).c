#include <stdio.h>

int combi[10];
int pick[10];
int N,K,flag=0;


void dfs(int start,int depth) {
	
	int i;

	
	if (depth == K)
	{
		
		if (flag == 1)
		{
			for (i = 0; i < K; i++)
			{
				printf("%d ", combi[i]);
			}
			exit(0);
		}

		int count = 0;

		for (i = 0; i < K; i++)
		{
			if (pick[i] == combi[i])
				count++;
		}
		if (count == K)
			flag = 1;

	}

	else
	{
		for (i = start; i <= N; i++)
		{
			combi[depth] = i;
			dfs(i + 1, depth + 1);
		}

	}
	

}


int main() {
	
	
	scanf("%d %d", &N,&K);

	for (int i = 0; i < K; i++)
		scanf("%d", &pick[i]);
	
	

	dfs(1,0);

	printf("NONE");

	return 0;
}
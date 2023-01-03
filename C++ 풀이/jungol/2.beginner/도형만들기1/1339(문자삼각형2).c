#include <stdio.h>

int main(void) {
	int num = 65; //A=65,Z=90
	int N;
	int arr[101][101] = { 0, };
	scanf("%d",&N);
	int center = (N / 2) + 1;
	int x = center;
	int y = center;
	int m = center;

	if (N < 1 || N>100 || N % 2 == 0) 
	{
		printf("INPUT ERROR\n");
		return 0; 
	}

	for (int i = 1; i <= m; ++i) {
		for (int j = 1; j <= 2 * i - 1; ++j) {
	
		arr[x++][y] = num++;
			if (num > 90) num = 65;
		}
		if (--center > 0) {
			x = center;
			y = center;
		}
	}

	for (int i = 1; i <= N; ++i) {
		for (int j = 1; j <= N; ++j) {
			if (arr[i][j] != 0)
				printf("%c " ,(char)arr[i][j]);
		}
		printf("\n");
	}

	return 0;
}
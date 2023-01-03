#include <stdio.h>
#pragma warning(disable:4996)

void main() {
	int s, e, i, j;
	scanf("%d %d", &s, &e);

	if (s < 2 || s>9 || e < 2 || e>9) // 2~9범위 작동 아닐시 다시입력
	{
		while (s < 2 || s>9 || e < 2 || e>9) {
			printf("INPUT ERROR!\n");
			scanf("%d %d", &s, &e);
		}
	}


	if (s > e)
	{
		for (i = s; i >= e; i--) {
			for (j = 1; j <= 9; j++) {
				printf("%d * %d = %2d   ", i, j, i * j);
				if (j % 3 == 0) printf("\n");
			}
			printf("\n");
		}
	}
	else {
		for (i = s; i <= e; i++) {
			for (j = 1; j <= 9; j++) {
				printf("%d * %d = %2d   ", i, j, i * j);
				if (j % 3 == 0) printf("\n");
			}
			printf("\n");
		}
	}
}

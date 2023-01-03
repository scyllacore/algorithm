#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(void)
{
	int i = 0, j = 0, k = 0, h = 1;


	scanf("%d", &j);
	int* p = (int*)malloc(sizeof(int) * j);

	for (i = 0; i < j; i++) {
		scanf("%d", &p[i]);
	}

	for (i = 0; i < j - 1; i++) {
		for (k = i + 1; k < j; k++) {
			if (p[i] < p[k]) {
				h = p[i];
				p[i] = p[k];
				p[k] = h;
			}
		}
	}

	for (i = 0; i < j; i++) {
		printf("%d ", p[i]);
	}
	free(p);
	return 0;
}
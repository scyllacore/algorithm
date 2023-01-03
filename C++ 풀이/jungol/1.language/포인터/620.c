#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	int i, j, n, tmp;
	scanf("%d", &n);
	int* p = (int*)malloc(sizeof(int) * n);

	for (i = 0; i < n; i++) {
		scanf("%d", &p[i]);
	}

	for (i = 0; i < n - 1; i++) {
		for (j = i + 1; j < n; j++) {
			if (p[i] < p[j]) {
				tmp = p[i];
				p[i] = p[j];
				p[j] = tmp;
			}
		}
	}

	for (i = 0; i < n; i++) {
		printf("%d ", p[i]);
	}
	free(p);

	return 0;
}
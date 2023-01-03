#include <stdio.h>

int main() {
	int i, j, n, type;
	scanf("%d %d", &n, &type);

	if (n > 100 || n < 0 || type<0 || type>3) {
		printf("INPUT ERROR!\n");
		return 0;
	}

	if (type == 1) {
		for (i = 1; i <= n; i++) {
			for (j = 1; j <= i; j++) {
				printf("*");
			}
			printf("\n");
		}
	}
	else if (type == 2) {
		for (i = n; i >= 1; i--) {
			for (j = 1; j <= i; j++) {
				printf("*");
			}
			printf("\n");
		}
	}
	else if (type == 3) {
		for (i = 1; i <= n; i++) {

			for (j = 1; j <= n-i; j++) {
				printf(" ");
			}

			for (j = 1; j <= 2*i-1; j++) {
				printf("*");
			}
			printf("\n");
		}
	}



}
#include <stdio.h>

int main() {
	int n;
	scanf("%d", &n);
	if (n >= 100 || n <= 0 || n % 2 == 0) {
		printf("INPUT ERROR!");
		return 0;
	}
	for (int i = 1; i <= (n + 1) / 2; i++) {
		for (int j = 1; j < i; j++) {
			printf(" ");
		}
		for (int j = 1; j < i + i; j++) {
			printf("*");
		}
		printf("\n");
	}
	for (int i = 1; i <= n / 2; i++) {
		for (int j = i; j < n / 2; j++) {
			printf(" ");
		}
		for (int j = 0; j < n - i - i; j++) {
			printf("*");
		}
		printf("\n");
	}

}
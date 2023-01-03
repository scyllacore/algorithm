#include <stdio.h>



int main() {


	int i, j, k, N, temp, min = 0, num[100] = { 0, };

	scanf("%d", &N);


	for (i = 0; i < N; i++) 
		scanf("%d", &num[i]);



	for (i = 0; i < N - 1; i++) {
		min = i;
		for (j = i + 1; j < N; j++) {
			if (num[j] < num[min]) {
				min = j;
			}
		}
		temp = num[i];
		num[i] = num[min];
		num[min] = temp;

		for (k = 0; k < N; k++) 
			printf("%d ", num[k]);
		printf("\n");
	}

}
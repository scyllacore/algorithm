#include <stdio.h>


int main() {


	int num[100] = { 0, }, i, j, k, N, temp;


	scanf("%d", &N);


	for (i = 0; i < N; i++)
		scanf("%d", &num[i]);


	for (i = 0; i < N - 1; i++) { // (i = N-1; i >=0; i--)
		for (j = 0; j < N - 1; j++) { // (j = 0; j < i; j++)
			if (num[j] > num[j + 1]) {
				temp = num[j + 1];
				num[j + 1] = num[j];
				num[j] = temp;
			}
			//한번 마칠 때 마다 큰 수가 제일 뒤로 감
		}



		for (k = 0; k < N; k++)
			printf("%d ", num[k]);
		printf("\n");

	}
}
#include <stdio.h>

int main() {


	int i, N, M, arr[100] = { 0, };
	int sum = 0, sum2 = 0;

	scanf("%d", &N);

	for (i = 1; i <= N; i++) {
		scanf("%d", &arr[i]);
	}

	scanf("%d", &M);


	for (i = 1; i <= N; i++) { // N = 6
		if (M % arr[i] == 0) // M = 12 % arr[i] 2, 3, 5, 12, 18, 24
			sum += arr[i];  // 2, 3, 12

		if (arr[i] % M == 0) // arr[i] 2, 3, 5, 12, 18, 24 % M = 12  
			sum2 += arr[i]; // 12, 24
	}

	printf("%d\n%d", sum, sum2);

}
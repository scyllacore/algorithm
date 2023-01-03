#include <stdio.h>

int main(void) {
	int i,N = 0;
	int arr[10000], cnt = 0;
	scanf("%d", &N);

	for (i = 1; i <= N / i; i++)
	{
		if (N % i == 0) arr[cnt++] = i;
	}

	int leftCnt = cnt - 1;

	for (i = leftCnt; i >= 0; i--)
	{
		if (N / arr[i] != arr[i]) arr[cnt++] = N / arr[i];
	}

	for (i = 0; i < cnt; i++) {
		printf("%d ", arr[i]);
	}

	return 0;
}
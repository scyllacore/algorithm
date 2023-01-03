#include <stdio.h>
int main() {
	int n, i, j;
	int arr[100][100];
	scanf("%d", &n);

	for (i = 1; i <= n; i++) {
		arr[i - 1][0] = i; // 첫번째 열
		for (j = 1; j < n; j++) { //나머지 열
			arr[i - 1][j] = (n + arr[i - 1][j - 1]); // 1 5 9 ..
		}
	}
	for (i = 0; i < n; i++) {
		for (j = 0; j < n; j++) {
			printf("%d ", arr[i][j]);
		}
		printf("\n");
	}
}
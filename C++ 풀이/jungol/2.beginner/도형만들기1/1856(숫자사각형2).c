#include <stdio.h>

int main()
{
	int n, m, i, j, num = 1;
	int arr[100][100];

	scanf("%d %d", &n, &m);

	for (i = 0; i < n; i++) { // 정방향
		if (i % 2 == 0) {
			for (j = 0; j < m; j++) {
				arr[i][j] = num++;
			}
		}
		else { // 역방향
			for (j = m - 1; j >= 0; j--) {
				arr[i][j] = num++;
			}
		}
	}
	for (i = 0; i < n; i++) {
		for (j = 0; j < m; j++) {
			printf("%d ", arr[i][j]);
		}
		printf("\n");
	}
	return 0;
}
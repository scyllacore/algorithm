#include <stdio.h>
int main(void) {
	int arr[100][100];
	int i, j, num = 0;
	int result = 65;
	scanf("%d", &num);

	for (i = 0; i < num; i++) {
		for (j = 0; j < num; j++) {
			arr[i][j] = result++;
			if (result > 90)
				result = 65;
		}
	}

	for (i = 0; i < num; i++) {
		for (j = 0; j < num; j++)
		{
			printf("%c ", arr[i][j]);
		}
		printf("\n");
	}
	return (0);
}

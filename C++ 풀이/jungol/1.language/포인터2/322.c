#include <stdio.h>
#include <stdlib.h>

int main()
{
	int i,j;
	int** arr = malloc(sizeof(int*) * (3 + 1));
	

	for (i = 0; i < 4; i++)
	{
		arr[i] = malloc(sizeof(int) * (2 + 1));
	}

	for (i = 0; i < 4; i++)
		for (j = 0; j < 3; j++)
			arr[i][j] = 0;



	for (i = 0; i < 3; i++)
		for (j = 0; j < 2; j++)
			scanf("%d", &arr[i][j]);

	for (i = 0; i < 3; i++)
		for (j = 0; j < 2; j++)
			arr[i][2] += arr[i][j];

	for (i = 0; i < 2; i++)
		for (j = 0; j < 3; j++)
			arr[3][i] += arr[j][i];

	for (i = 0; i < 2; i++)
		arr[3][2] += arr[3][i];


	for (i = 0; i < 4; i++) {
		for (j = 0; j < 3; j++) {
			printf("%d ", arr[i][j]);
		}
		printf("\n");
	}


}
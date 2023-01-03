#include <stdio.h>
#include <stdlib.h>

typedef struct class {
	char name[20];
	int height;
	float weight;

} classdef;


void swap(classdef* swap1, classdef* swap2)
{
	classdef copy;
	copy = *swap1;
	*swap1 = *swap2;
	*swap2 = copy;

}


int main()
{
	classdef arr[5];
	int i, j;

	int arrlen = sizeof(arr) / (sizeof(int) + 20);

	for (i = 0; i < 5; i++) {
		scanf("%s %d %f", &arr[i].name, &arr[i].height, &arr[i].weight);
	}


	for (i = 0; i < arrlen - 1; i++)
		for (j = i + 1; j < arrlen; j++)
			if (strcmp(arr[i].name, arr[j].name) > 0)
				swap(&arr[i], &arr[j]);

	printf("name\n");
	for (i = 0; i < 5; i++) {
		printf("%s %d %.1f\n", arr[i].name, arr[i].height, arr[i].weight);
	}
	printf("\n");





	for (i = 0; i < arrlen - 1; i++)
		for (j = i + 1; j < arrlen; j++)
			if (arr[i].weight < arr[j].weight)
				swap(&arr[i], &arr[j]);

	printf("weight\n");

	for (i = 0; i < 5; i++) {
		printf("%s %d %.1f\n", arr[i].name, arr[i].height, arr[i].weight);
	}
	printf("\n");





	/*for (i = 0; i < arrlen - 1; i++)
		for (j = i + 1; j < arrlen; j++)
			if (arr[i].height < arr[j].height)
				swap(&arr[i], &arr[j]);
	printf("name\n");

	for (i = 0; i < 5; i++) {
		printf("%s %d %.1f\n", arr[i].name, arr[i].height, arr[i].weight);
	}
	printf("\n");
	*/
	return 0;
}
#include <stdio.h>

typedef struct class {
	char name[20];
	int height;

} classdef;


void swap(classdef* swap1,classdef* swap2)
{
	classdef copy;
	copy = *swap1;
	*swap1 = *swap2;
	*swap2 = copy;

}


int main()
{
	classdef arr[5];
	int i,j;

	int arrlen = sizeof(arr)/(sizeof(int)+20);

	for (i = 0; i < 5; i++) {
		scanf("%s %d", &arr[i].name, &arr[i].height);
	}

	for (i = 0; i < arrlen - 1; i++)
		for (j = i+1; j < arrlen; j++)
			if (arr[i].height > arr[j].height)
				swap(&arr[i], &arr[j]);


	printf("%s %d  \n", arr[0].name, arr[0].height);

	return 0;
}
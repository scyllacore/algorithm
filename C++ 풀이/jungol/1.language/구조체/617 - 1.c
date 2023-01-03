#include <stdio.h>

typedef struct class {
	char name[20];
	int height;

} classdef;


int main()
{
	classdef arr[5];
	int i,j;

	scanf("%s %d", &arr[0].name, &arr[0].height);
	mintall = arr[0].height;

	for (int i = 1; i < 5; i++) {
		scanf("%s %d", &arr[i].name, &arr[i].height);
		if (mintall > arr[i].height) {
			min = i;
			mintall = arr[i].height;
		}
	}
	printf("%s %d  \n", arr[min].name, arr[min].height);

	return 0;
}
#include <stdio.h>


int main(void)
{
	int* p1 = (int*)malloc(sizeof(int));
	int* p2 = (int*)malloc(sizeof(int));
	scanf("%d %d", p1, p2);

	printf("%d + %d = %d\r\n", *p1, *p2, *p1 + *p2);
	printf("%d - %d = %d\r\n", *p1, *p2, *p1- *p2);
	printf("%d * %d = %d\r\n", *p1, *p2, *p1 * *p2);
	printf("%d / %d = %d\r\n", *p1, *p2, *p1 / *p2);

	return 0;
}
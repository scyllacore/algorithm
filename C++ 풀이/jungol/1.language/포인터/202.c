#include <stdio.h>
#include <math.h>

int main()
{
    int* n1 = (int*)malloc(sizeof(int));
    int* n2 = (int*)malloc(sizeof(int));
    int* result = (int*)malloc(sizeof(int));
    scanf("%d %d", n1, n2);

    *result = abs(*n1 - *n2);
    printf("%d", *result);
}
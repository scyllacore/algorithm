#include <stdio.h>

int main()
{
    int n;
    int* p = &n;
    scanf("%d", &n);

    int i;
    for (i = 0; i < *p; i++) {
        printf("*");
    }
}
#include <stdio.h>
#include <limits.h> 

int main()
{
    int n;
    scanf("%d", &n);

    int* p = (int*)malloc(sizeof(int) * n);
    int i;
    int max = INT_MIN, min = INT_MAX;
    for (i = 0; i < n; i++) {
        scanf("%d", &p[i]);
        if (p[i] > max) max = p[i];
        if (p[i] < min) min = p[i];
    }
    printf("max : %d\n", max);
    printf("min : %d", min);
}
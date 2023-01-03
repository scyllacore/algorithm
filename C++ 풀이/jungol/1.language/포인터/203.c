#include <stdio.h>

int main()
{
    int num[10],i;
    int* p = num;
    int odd = 0, even = 0;
    for (i = 0; i < 10; i++) {
        scanf("%d", &p[i]);
        if (p[i] % 2 == 0) even++;
        else odd++;
    }
    printf("odd : %d\n", odd);
    printf("even : %d", even);
}
#include <stdio.h>

void Swap(int** pp, int** qq)
{
    int* tmp;

    tmp = (*pp);
    (*pp) = (*qq);
    (*qq) = tmp;

}

int main()
{
    int a, b;
    scanf("%d %d", &a, &b);
    int* p = &a, * q = &b;

    Swap(&p, &q);

    printf("%d %d\n", a, b);
    printf("%d %d\n", *p, *q);

    return 0;
}
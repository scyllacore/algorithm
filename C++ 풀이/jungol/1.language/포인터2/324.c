#include <stdio.h>

// visual studio¿¡¼­ ¾ÈµÊ

int add(int a, int b)
{
    return a + b;
}

int dif(int a, int b)
{
    return a - b;
}


int main()
{

    int x, y;

    scanf("%d %d", &x, &y);

    int (*p1) (int a, int b);
    int (*p2) (int a, int b);


    p1 = add;
    p2 = dif;

    printf("sum = %d\n", p1(x, y));
    printf("sub = %d\n", p2(x, y));

}
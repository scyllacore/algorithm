#include <stdio.h>

int main()
{
    char a[3][5];

    int i,j;
    for(i=0;i<3;i++){
        for(j=0;j<5;j++){
            scanf(" %c", &a[i][j]);
        }
    }
    for(i=0;i<3;i++){
        for(j=0;j<5;j++){
            printf("%c ", a[i][j]+32);
        }
        printf("\n");
    }
}
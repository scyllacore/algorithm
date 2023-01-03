#include <stdio.h>

int main()
{
    int a[10];
    int tmp, i, j;
    for(i=0;i<10;i++){
        scanf("%d", &a[i]);
    }
    for(i=0;i<9;i++){
        for(j=i+1;j<10;j++){
            if(a[i] < a[j]){
                tmp = a[i];
                a[i] = a[j];
                a[j] = tmp;
            }
        }
    }
    for(i=0;i<10;i++) printf("%d ", a[i]);
}

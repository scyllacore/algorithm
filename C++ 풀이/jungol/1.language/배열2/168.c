#include <stdio.h>

int main()
{
    int arr[20][20] = { {0} };
    int num;
    int i, j;

    scanf("%d", &num);

    /*
    
    arr[1][1] = 1;
    
    for (i = 2; i <= num; i++) {
        for (j = 1; j <= num; j++) {
            arr[i][j] = arr[i - 1][j] + arr[i - 1][j - 1];
        }
    }

    for (i = 0; i <= num; i++) {
        for (j =0; j <= num; j++) {  
                printf("%d ", arr[i][j]); 
        }
        printf("\n");
    }*/

    arr[0][0] = 1;

    for (i = 1; i <= num; i++) {
        for (j = 1; j <= num; j++) {
            arr[i][j] = arr[i - 1][j] + arr[i - 1][j - 1];
        }
    }

    for (i = num; i > 0; i--) {
        for (j = num; j > 0; j--) {
            if (arr[i][j] != 0) {
                printf("%d ", arr[i][j]);
            }
        }
        printf("\n");
    }


}
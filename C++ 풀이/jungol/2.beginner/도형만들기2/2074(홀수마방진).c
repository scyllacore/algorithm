#include <stdio.h>



int main() {

    int n;
    int i,j;  // 배열에 순서대로 채울 값 (for 문에 사용할 변수)

    scanf("%d", &n);

    int** arr = malloc(sizeof(int*) * n);

    for (i = 0; i < n; i++)
        arr[i] = malloc(sizeof(int) * n);



    int x = n / 2; // 행 - 처음에는 1
    int y = 0; // 열 - 초기값 중앙
    int end = n * n; // 배열에 채울 마지막 값

    for (i = 1; i <= end; i++)   // 배열에 채울 값 1부터 end까지
     {
        arr[y][x] = i; // i를 배열의 현재 위치에 넣는다.
        if (i % n == 0) y++;  // 만약 현재의 수가 n의 배수이면 아래로 이동
         else
           {
              x--, y--; // 왼쪽 위로 이동
              if (x < 0) x = n-1; // x가 0이면 n으로
              if (y < 0) y = n-1; // y가 0이면 n으로
           }
     }


       for (i = 0; i < n; i++)
        {
           for (j = 0; j < n; j++)
           {
               printf("%d ", arr[i][j]);
           }
           printf("\n");
        }

    }


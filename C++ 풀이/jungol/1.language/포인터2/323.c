#include <stdio.h>


// 코드 전체 제출 해야함

void process(int n, int m, int arr[][10], int **max, int **min)
{
    int i, j;

   *max = *min = &arr[0][0];

    for (i = 0; i < n; i++) {
        for (j = 0; j < m; j++)
        {
            if (**max < arr[i][j])
                *max = &arr[i][j];

            if (**min > arr[i][j])
                *min = &arr[i][j];

        }
    }

}


int main()
{
    int N, M, arr[10][10];
    int* maxadr, * minadr;

    scanf("%d %d", &N, &M);
    for (int i = 0; i < N; i++)
        for (int j = 0; j < M; j++)
            scanf("%d", &arr[i][j]);

    process(N, M, arr, &maxadr, &minadr);
    printf("%d %d\n", *maxadr, *minadr);
    return 0;
}

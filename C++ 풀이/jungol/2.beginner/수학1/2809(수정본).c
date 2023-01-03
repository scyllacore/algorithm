#include <stdio.h>

int main(void) {
    int i = 0;
    int N = 0;
    int arr[10000], cnt = 0;
    scanf("%d", &N);

    for (i = 1; i * i <= N; i++)
    {
        if (N % i == 0)
        {
            arr[cnt++] = i;
            if (N / i != i)
                arr[cnt++] = N / i;
        }
    }


    for (i = 0; i < cnt; i = i + 2) {
        printf("%d ", arr[i]);
    }

    if (cnt % 2 == 1){ cnt--;}

    for (i = cnt - 1; i > 0; i = i - 2) {
        printf("%d ", arr[i]);
    }
}
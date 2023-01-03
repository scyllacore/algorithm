#include <stdio.h>

//SDL(Security Development Lifecycle) 검사 아니요로

int sum(int arr[], int n)
{
    int i,sum=0;

    for (i = 0; i < n; i++)
        sum += arr[i];

    return sum;

}

int maxnum(int arr[], int n)
{
    int i, max = arr[0];


    for (i = 0; i < n; i++)
        if(arr[i]>max)
         max = arr[i];

    return max;

}

int minnum(int arr[], int n)
{
    int i, min = arr[0];


    for (i = 0; i < n; i++)
        if (arr[i] < min)
            min = arr[i];

    return min;

}


int calculation(int arr[],int n,int (*fuction)(int arr[],int n)){
    
    int result;

    result = (*fuction)(arr, n);

    return result;
}


int main()
{
    int N, M, a[10], res;
    scanf("%d %d", &N, &M);
    for (int i = 0; i < N; i++) {
        scanf("%d", a + i);
    }

    if (M == 1) res = calculation(a, N, sum);
    else if (M == 2) res = calculation(a, N, maxnum);
    else if (M == 3) res = calculation(a, N, minnum);

    printf("result = %d\n", res);
    return 0;
}

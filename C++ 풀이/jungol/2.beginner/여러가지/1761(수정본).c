#include <stdio.h>
#include <stdlib.h>

typedef struct Baseball {
    char num[3];
    int strike;
    int ball;
} Num;

int cnt_strike(char arr1[], char arr2[])
{
    int strike = 0;
    for (int i = 0; i < 3; i++)
    {
        if (arr1[i] == arr2[i])
            strike++;
    }
    return strike;
}

int cnt_ball(char arr1[], char arr2[])
{
    int ball = 0;
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (arr1[i] == arr2[j])
            {
                if (i == j)
                    continue;
                ball++;
            }
        }
    }
    return ball;
}

int main()
{
    int n, i, j, k, cnt = 0, result = 0;
    scanf("%d", &n);
    Num* input_num = malloc(sizeof(Num) * n);
    Num arr[504];
    for (i = 0; i < n; i++)
        scanf("%s %d %d", input_num[i].num, &input_num[i].strike, &input_num[i].ball);
    for (i = 1; i < 10; i++)
    {
        for (j = 1; j < 10; j++)
        {
            for (k = 1; k < 10; k++)
            {
                if (i == j)
                    break;
                else if (i == k || j == k)
                    continue;
                arr[cnt].num[0] = i + 48, arr[cnt].num[1] = j + 48, arr[cnt++].num[2] = k + 48;
            }
        }
    }
    for (i = 0; i < 504; i++)
    {
        for (j = 0; j < n; j++)
        {
            if (cnt_strike(arr[i].num, input_num[j].num) != input_num[j].strike || cnt_ball(arr[i].num, input_num[j].num) != input_num[j].ball)
                break;
        }
        if (j == n)
            result++;
    }
    printf("%d", result);
    return 0;
}
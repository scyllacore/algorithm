#include <stdio.h>

int drawingPaper[101][101] = { 0 };

int sideCalculator(int max_x, int max_y);
int count_fuc(int x, int y);

int main(void)
{
    int n, i, j, k, sum = 0;
    int x, y, max_x = -999,max_y = -999;


    scanf("%d", &n); //색종이의 수 입력

    for (k = 0; k < n; k++)
    {
        scanf("%d %d", &x, &y); //색종이의 위치 입력 

        if (max_x < x)
            max_x = x;
        if (max_y < y)
            max_y = y;

        for (i = x; i < (x + 10); i++)
        {
            for (j = y; j < (y + 10); j++)
            {
                drawingPaper[i][j] = 1; //색종이인 부분 체크 
            }
        }
    }


    sum = sideCalculator(max_x,max_y);

    printf("%d", sum);

    return 0;
}


int sideCalculator(int max_x,int max_y)
{
    int sum = 0, i, j;

    max_x += 10;
    max_y += 10;

    //방문용 for
    for (i = 1; i < max_x ; i++)
    {
        for (j = 1; j < max_y ; j++)
        {
            if (drawingPaper[i][j] == 1) //색종이인 부분 
                sum = sum + count_fuc(i, j);
        }

    }

    return sum;
}

int count_fuc(int x, int y)
{
    int cnt = 0;

    //변인지 체크 
    if (drawingPaper[x + 1][y] == 0) cnt++;
    if (drawingPaper[x - 1][y] == 0) cnt++;
    if (drawingPaper[x][y + 1] == 0) cnt++;
    if (drawingPaper[x][y - 1] == 0) cnt++;

    return cnt;
}
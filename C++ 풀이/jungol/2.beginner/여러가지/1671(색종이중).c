#include <stdio.h>
#define MAX 101
 
int all[MAX][MAX]={0};
 
int line(void);
int countf(int x, int y);
void pr(void);
 
int main(void)
{
    int n, i, j, k, sum=0, x, y;
 
    scanf("%d", &n); //색종이의 수 입력
 
    for(i=0; i<n; i++)
    {
        scanf(" %d %d", &x, &y); //색종이의 위치 입력 
 
        for(j=x; j<(x+10); j++)
        {
            for(k=y; k<(y+10); k++)
            {
                all[j][k]=1; //색종이인 부분 체크 
            }
        }
    }
 
 
    //pr();
 
    sum=line();
 
    printf("%d", sum);
 
    return 0;
}
 
void pr(void) //전체 출력 
{
    int i, j;
 
    for(i=MAX-1; i>=0; i--)
    {
        for(j=0; j<MAX; j++)
        {
            printf("%d ", all[j][i]);
        }
        printf("\n");
    }
 
}
 
int line(void)
{
    int sum=0, i, j;
 
    //방문용 for
    for(i=1; i<MAX-1; i++)
    {
        for(j=1; j<MAX-1; j++)
        {
            if(all[i][j]==1) //색종이인 부분 
                sum=sum+countf(i, j);
        }
 
    }
 
    return sum;
}
 
int countf(int x, int y)
{
    int cnt=0;
 
    //변인지 체크 
    if(all[x+1][y]==0) cnt++;
    if(all[x-1][y]==0) cnt++;
    if(all[x][y+1]==0) cnt++;
    if(all[x][y-1]==0) cnt++;
 
    return cnt; 
}
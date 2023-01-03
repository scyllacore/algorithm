#include <stdio.h>
 
int squ[100][100]={0};
 
int square(int * m);
int main(void)
{
    int n, m[2], i, sum=0;
 
    scanf("%d", &n);
 
    for(i=0; i<n; i++)
    {
        scanf(" %d %d", &m[0], &m[1]);
        sum+=square(m);
    }
 
    printf("%d", sum);
 
    return 0;
}
int square(int * m)
{
    int i, j, c=0;
 
    for(i=m[0]; i<(m[0]+10); i++)
    {
        for(j=m[1]; j<(m[1]+10); j++)
        {
            if(squ[i][j]==0)
            {
                squ[i][j]=1;
                c++;
            }
        }
    }
 
    return c;
}
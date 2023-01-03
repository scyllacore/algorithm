#include <stdio.h>
 
int num[5]={0};
 
int one(int n, int a);
int two(int n, int a);
int three(int n, int a);
int main(void)
{
    int n, m;
 
    scanf("%d %d", &n, &m);
 
    switch(m)
    {
        case 1:
            one(n, 0);
            break;
 
        case 2:
            two(n, 0);
            break;
 
        case 3:
            three(n, 0);
            break;
    }
 
    return 0;
}
 
int one(int n, int a)
{
    int i, j;
 
    for(i=1; i<=6; i++)
    {
        //printf("i= %d a= %d \n", i, a);
        num[a]=i;
 
        if(a<n-1)
            one(n, a+1);
 
        else
        {
            for(j=0; j<n; j++)
                printf("%d ", num[j]);
            printf("\n");
        }
 
    }
    //printf("----------------------------------------------------\n");
 
 
    return 0;
}
 
int two(int n, int a)
{
    int i, j;
 
    for(i=1; i<=6; i++)
    {
        if(num[a-1]<=i)
        {
            num[a]=i;
 
            if(a<n-1)
                two(n, a+1);
 
            else
            {
                for(j=0; j<n; j++)
                    printf("%d ", num[j]);
                printf("\n");
            }
        }
    }
 
    return 0;
}
 
int three(int n, int a)
{
    int i, j, k, aa;
 
    for(i=1; i<=6; i++)
    {
        aa=0;
        for(k=0; k<a; k++)
        {
            if(num[k]==i)
            {
                aa=1;
                break;
            }
        }
 
        if(aa==0)
        {
            num[a]=i;
 
            if(a<n-1)
                three(n, a+1);
 
            else
            {
                for(j=0; j<n; j++)
                    printf("%d ", num[j]);
                printf("\n");
            }
        }
    }
 
    return 0;
}
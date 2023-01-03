#include<stdio.h>
int main()
{
    int a[6],b[6],k=0,i,n=0,sum=0,max=0;
    scanf("%d",&n);
    for(i=0;i<6;i++)
    {
        scanf("%d%d",&a[i],&b[i]);
    }
    for(i=0;i<6;i++)
    {
        if(max<b[i]*b[(i+1)%6])
        {
            max=b[i]*b[(i+1)%6];
            k=i;
        }
    }
    sum=b[(k+3)%6]*b[(k+4)%6];
    max=max-sum;
    printf("%d",max*n);
}


//출처: https://plzfdaylife.tistory.com/54 [CS 스케치북]
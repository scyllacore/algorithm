#include <cstdio>

int main()
{
    int t,h,w,n;
    
    scanf("%d",&t);
    
    
    for(int i=0; i<t; i++)
    {
        scanf("%d %d %d",&h,&w,&n);
        
        
        printf("%d",n%h==0?h:n%h);
        printf("%02d\n",n%h==0?n/h:n/h+1);
    }
    
    return 0;
    
    
    
}
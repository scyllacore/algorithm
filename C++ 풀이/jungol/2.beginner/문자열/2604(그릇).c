#include <stdio.h>
 
int main(void)
{
    int i, sum=0;
    char dish[55];
 
    scanf("%s", dish);
 
    sum=10;
    for(i=1; dish[i]=='(' || dish[i]==')'; i++)
    {
        if(dish[i]==dish[i-1])
            sum+=5;
        else
            sum+=10;

    }
 
    printf("%d", sum);
 
    return 0;
}

//처음에 설정 해둔 값은 제치고 그 다음 인덱스를 기준으로 했을 때 i , i-1같은 식이 나온다 i,i+1은 쓰지말 것
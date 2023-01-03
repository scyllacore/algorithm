#include <stdio.h>
#include <string.h>
 
int change(char t[])
{
    int i, len, ten=0;
    len = strlen(t);
    for (i=0; i<len; i++)
    {
        ten = ten*2+(t[i]-'0');  //앞자리까지의 값에 2를 곱하고 현재의 값을 더한다.
    }
    return ten;
}
 
int main()
{
    char two[35];
    scanf("%s", two);
    printf("%d\n", change(two));
    return 0;
}

/*
#include <stdio.h>
#include <string.h>
 
int change(char t[], int len)
{
    if (len==0) return 0;
    return change(t, len-1) * 2 + (t[len-1]-'0');
}
 
int main()
{
    char two[35];
    scanf("%s", two);
    printf("%d\n", change(two, strlen(two)));
    return 0;
}
 
*/


//  ten*2 -> ten*10 으로하여 10진법으로 가정하고 설명한다
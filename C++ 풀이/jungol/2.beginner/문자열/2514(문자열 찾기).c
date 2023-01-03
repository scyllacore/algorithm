#include <stdio.h>
 
char word[10000];
int k, i;
 
void count(void); //찾기 
void koi(int a); //KOI인가? 
void ioi(int a); //IOI인가? 
int main(void)
{   
    scanf("%s", word);
 
    count();
 
    printf("%d\n%d", k, i);
    return 0;
}
void count(void)
{
    int i;
    for(i=0; word[i]!='\0'; i++)
    {
        if(word[i]=='K')
            koi(i);
        else if(word[i]=='I')
            ioi(i);
    }
}
void koi(int a)
{
    if(word[a]=='K' && word[a+1]=='O' && word[a+2] =='I')
        k++;
}
void ioi(int a)
{
    if(word[a]=='I' && word[a+1]=='O' && word[a+2] =='I')
        i++;
}
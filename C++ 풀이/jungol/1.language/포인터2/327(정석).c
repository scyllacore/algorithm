#include <stdio.h>
#include <string.h>

void shortname(int n, char(*name)[21], char** name1, char** name2)
{
    int i,j, len;
    int flag1 = 0, flag2 = 0;

    int minlen = 999;

    for (i = 0; i < n; i++)
    {
        len = strlen(name[i]);

        if (len < minlen) {
            minlen = len;
        }
    } // 가장 짧은 단어 검사


    for (;;)
    {   //순서대로 가장 짧은 단어 검사
        for (i = 0; i < n ;i++)
        {
            if (flag1 == 1) // 결정된 name1은 pass
                break;

            if ((minlen == strlen(name[i]))) 
            {
                flag1 = 1;
                *name1 = name[i++]; // 나왔을시에 name1에 넣고 다음 것 검사를 위해 i++

                break;
            }
        }

        for (; i < n; i++)
        {
            if (minlen == strlen(name[i])) //  그 다음에 짧은 것 찾아서 있으면
            {
                flag2 = 1;
                *name2 = name[i]; // name2에 넣음
                break; 
            }
        }

        if (flag1==1 && flag2==1) // 다 검사했으면 멈춤
            break;
        
        minlen++;
    }

    return;
}

int main()
{
    int N, i;
    char name[10][21], * short1, * short2;
    scanf("%d", &N);
    for (i = 0; i < N; i++) {
        scanf("%s", name[i]);
    }
    shortname(N, name, &short1, &short2);
    printf("%s\n%s\n", short1, short2);
    return 0;
}

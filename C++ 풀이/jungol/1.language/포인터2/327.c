#include <stdio.h>
#include <string.h>

void shortname(int n, char(*name)[21], char** name1, char** name2)
{
    int i,len,minlen_i=0;

    int minlen1, minlen2;
    minlen1 = minlen2 = 999;

    for (i = 0; i < n; i++)
    {
        len = strlen(name[i]);

        if (len < minlen1) {
            minlen1 = len;
            *name1 = name[i];
            minlen_i = i;
        }
    }


    for (i = 0; i < n; i++)
    {

        if (i == minlen_i)
            continue;

        len = strlen(name[i]);

        if (len < minlen2) {
            minlen2 = len;
            *name2=name[i];
        }
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

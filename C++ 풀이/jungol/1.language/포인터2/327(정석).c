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
    } // ���� ª�� �ܾ� �˻�


    for (;;)
    {   //������� ���� ª�� �ܾ� �˻�
        for (i = 0; i < n ;i++)
        {
            if (flag1 == 1) // ������ name1�� pass
                break;

            if ((minlen == strlen(name[i]))) 
            {
                flag1 = 1;
                *name1 = name[i++]; // �������ÿ� name1�� �ְ� ���� �� �˻縦 ���� i++

                break;
            }
        }

        for (; i < n; i++)
        {
            if (minlen == strlen(name[i])) //  �� ������ ª�� �� ã�Ƽ� ������
            {
                flag2 = 1;
                *name2 = name[i]; // name2�� ����
                break; 
            }
        }

        if (flag1==1 && flag2==1) // �� �˻������� ����
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

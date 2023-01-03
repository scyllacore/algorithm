#include <stdio.h>
#include <string.h>

int main()
{
    char str[3][100];
    char tmp[100];

    int i, j;

	for ( i = 0; i < 3; i++)
	{
		scanf(" %s", str[i]);
	}


    for (i = 0; i <2; i++) {
        for (j = i+1; j<3; j++) {
            if (strcmp(str[i],str[j]) > 0) {
                strcpy(tmp,str[i]);
                strcpy(str[i],str[j]);
                strcpy(str[j],tmp);
            }
        }
    }

   /*for (i = 0; i < 3; i++)
    {
        printf("%s", str[i]);
    }*/

    printf("%s", str[0]);

    return 0;

}
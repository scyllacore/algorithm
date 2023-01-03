#include <stdio.h>
#include <string.h>

int main()
{
	char str[51] = { 0 };
	char words[100][51];
	int i,cnt=0,flag;

	for (;;)
	{
		gets(str);

		if (strcmp(str, "END") == 0)
		{
			break;
		}

		char* ptr = strtok(str, " ");


		while (ptr != NULL)
		{
			flag = 1;
			for (i = 0; i < cnt; i++)
			{
				if (strcmp(ptr, words[i]) == 0)
				{
					flag = 0;
					break;
				}
			}
			if (flag == 1) {
				strcpy(words[cnt++], ptr);		
			}
			ptr = strtok(NULL, " ");

		}

		for (i = 0; i < cnt; i++)
		{
			printf("%s ", words[i]);
		}
		printf("\n");

	}


	



}
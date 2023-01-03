#include <stdio.h>
#include <string.h>

int main()
{
	int i, j;
	char words[100][100] = { {0} };
	char words2[100] = { 0 };

	/*for (i = 0; ;i++)
	{
		scanf(" %s", words[i]);
		
		if (strcmp(words[i], "END") == 0)
			break;

		for (j = strlen(words[i])-1; j >= 0; j--)
		{
			printf("%c", words[i][j]);
		}
		printf("\r\n");
	}*/

	for (;;)
	{
		scanf(" %s", words2);

		if (strcmp(words2, "END") == 0)
			break;

		for (i = strlen(words2)-1; i >= 0; i--)
		{
			printf("%c", words2[i]);
		}
		printf("\r\n");
	}
	return 0;
	
}
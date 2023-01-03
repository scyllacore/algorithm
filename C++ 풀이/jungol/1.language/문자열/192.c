#include <stdio.h>
#include <string.h>

int main()
{
	int i, j;
	char words[100][100] = { {0} };
	int n;
	char tmp[100] = { 0 };

	scanf("%d", &n);

	for (i = 0; i < n; i++)
		scanf(" %s", words[i]);

	for(i=0; i<n-1; i++)
		for (j = i + 1; j < n; j++)
		{
			if (strcmp(words[i], words[j]) > 0)
			{
				strcpy(tmp,words[i]);
				strcpy(words[i],words[j]);
				strcpy(words[j],tmp);
			}
		}

	for (i = 0; i < n; i++)
		printf("%s\r\n", words[i]);

	return 0;
	
}
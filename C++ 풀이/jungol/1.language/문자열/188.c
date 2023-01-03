#include <stdio.h>
#include <string.h>

int main()
{
	char str[100] = { 0 };
	int i = 0;
	int num = 0;
	gets(str);
	
	
	for (; str[num] != NULL && str[num] != '\n'; num++)
	{
		printf("%d. ", 1 + i++);
		for (; str[num] != ' ' && str[num] != NULL;)
		{
			printf("%c", str[num++]);
		}
		printf("\n");
	

	}
}
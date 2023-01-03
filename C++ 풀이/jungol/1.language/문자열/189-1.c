#include <stdio.h>
#include <string.h>

int main()
{
	char str[100] = { 0, };
	char words[20][20] = { 0, };
	int nextWord = 0, cnt = 0,i;

	gets(str);

	for (i = 0; i < strlen(str); i++) {
		if (str[i] == ' ')
		{
			nextWord++;
			cnt = 0;
		}
		else {
			words[nextWord][cnt++] = str[i];
		}

	}

	for (i = nextWord; i>= 0; i--)
	{
		printf("%s\r\n", words[i]);

}

	return 0;
}
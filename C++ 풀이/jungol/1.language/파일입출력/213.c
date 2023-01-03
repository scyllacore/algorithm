#include <stdio.h>
#include <string.h>

typedef struct msg {
	char s[100];
	int len;
}msg;

int main()
{
	int i = 0, max;
	char str[100];
	char* ptr;
	msg m[100];

	fgets(str, 100, stdin);
	fprintf(stdout, "%d\n", strlen(str));

	ptr = strtok(str, " ");

	while (ptr)
	{
		strcpy(m[i].s, ptr);
		m[i].len = strlen(m[i].s);
		i++;
		ptr = strtok(NULL, " ");
	}

	max = m[0].len;
	for (int j = 0; j < i; j++)
	{
		if (max < m[j].len)
			max = m[j].len;
	}

	for (int j = 0; j < i; j++)
	{
		if (m[j].len == max)
			fprintf(stdout, "%s ", m[j].s);
	}

	return 0;
}
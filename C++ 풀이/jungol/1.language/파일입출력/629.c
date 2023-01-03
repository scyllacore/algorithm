# include <stdio.h>
# include <string.h>

int main()
{
	char num1[101];
	char num2[101];

	fgets(num1, 100, stdin);
	fgets(num2, 100, stdin);

	fprintf(stdout, "%s", strlen(num1) > strlen(num2) ? num2 : num1);
	fprintf(stdout, "%s", strlen(num1) > strlen(num2) ? num1 : num2);

	return 0;
}
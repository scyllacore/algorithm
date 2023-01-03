#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
	int n, i, idx = 0;
	fscanf(stdin, "%d ", &n);

	char** string_arr = malloc(sizeof(char*) * n);


	for (i = 0; i < n; i++) {
		string_arr[i] = malloc(sizeof(char) * 100);
	}


	for (i = 0; i < n; i++) {
		fgets(string_arr[i],100,stdin);
	}

	for (i = n - 1; i > -1; i--)
	{
		fprintf(stdout, "%s", string_arr[i]);
	}

	return 0;



}
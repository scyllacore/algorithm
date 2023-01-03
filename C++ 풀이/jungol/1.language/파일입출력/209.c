#include <stdio.h>

int main()
{
	int arr[1000];
	int tmp, i = 0;

	while (1)
	{
		fscanf(stdin, "%d", &tmp);

		if (!tmp)
			break;

		if (!(tmp % 5) && !(tmp % 3)) {
			arr[i++] = tmp;
		}
	}

	if (!i)
		printf("0");
	else
	{
		for (int j = 0; j < i; j++)
			fprintf(stdout, "%d ", arr[j]);
		fprintf(stdout, "\n%d", i);
	}

	return 0;
}
#include <stdio.h>

int main()
{
	int h, t;
	int count = 0;

	fscanf(stdin, "%d %d", &h, &t);

	for (int i = h; i <= t; i++)
	{
		if ((!(i % 4) && (i % 100)) || !(i % 400))
			count++;
	}

	fprintf(stdout, "%d", count);

	return 0;
}
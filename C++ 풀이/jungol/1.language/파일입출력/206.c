#include <stdio.h>

int main()
{
	int x, y, z;

	fscanf(stdin, "%d %d %d", &x, &y, &z);

	fprintf(stdout, "%d %d...%d", x + y + z, (x + y + z) / 3, (x + y + z) % 3);

	return 0;
}
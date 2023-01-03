#include <stdio.h>

int main()
{
	int x, y, result;
	char op;

	fscanf(stdin, "%d %d %c", &x, &y, &op);

	switch (op)
	{
	case '+':
		result = x + y;
		break;
	case '-':
		result = x - y;
		break;
	case '/':
		result = x / y;
		break;
	case '%':
		result = x % y;
		break;
	case '*':
		result = x * y;
		break;
	}

	fprintf(stdout, "%d %c %d = %d", x, op, y, result);

	return 0;
}
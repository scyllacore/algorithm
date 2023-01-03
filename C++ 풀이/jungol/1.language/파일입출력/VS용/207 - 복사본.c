#include <stdio.h>
#include <string.h>
#include <conio.h>

typedef struct file_rw
{
	FILE* read;
	FILE* write;
}file;

file fp;

int file_open()
{
	fp.read = fopen("input207.txt", "rt");
	fp.write = fopen("output207.txt", "wt");

	if (fp.read == NULL) {
		printf("파일열기 실패\n");
		return 0;
	}
	else {
		printf("파일열기 성공\n");
		return 1;
	}

}


int main()
{

	if (file_open() == 0) {
		_getche();
		return -1;
	}

	int x, y, result;
	char op;

	fscanf(fp.read, "%d %d %c", &x, &y, &op);

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

	fprintf(fp.write, "%d %c %d = %d", x, op, y, result);

	_fcloseall();
	_getche();

	return 0;


}
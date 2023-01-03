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
	fp.read = fopen("input629.txt", "rt");
	fp.write = fopen("output629.txt", "wt");

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

	int i;
	char str[2][100];

	for (i = 0; i < 2; i++)
	{
		fgets(str[i], 100, fp.read);
		str[i][strlen(str[i]) - 1] = NULL;
	}

	fprintf(fp.write, "%s\n", strlen(str[0]) > strlen(str[1]) ? str[1] : str[0]);
	fprintf(fp.write, "%s", strlen(str[0]) > strlen(str[1]) ? str[0] : str[1]);

	_fcloseall();
	_getche();

	return 0;
}
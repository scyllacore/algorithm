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
	fp.read = fopen("input630.txt", "rt");
	fp.write = fopen("output630.txt", "wt");

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

	int n, i, idx = 0;
	fscanf(fp.read, "%d ", &n);

	char** string_arr = malloc(sizeof(char*) * n);


	for (i = 0; i < n; i++) {
		string_arr[i] = malloc(sizeof(char) * 100);
	}


	for (i = 0; i < n; i++) {
		fgets(string_arr[i], 100, fp.read);
		string_arr[i][strlen(string_arr[i]) - 1] = NULL;
	}

	for (i = n - 1; i > -1; i--)
	{
		fprintf(fp.write, "%s\n", string_arr[i]);
	}

	_fcloseall();
	_getche();

	return 0;



}
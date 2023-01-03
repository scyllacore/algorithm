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
	fp.read = fopen("input209.txt", "rt");
	fp.write = fopen("output209.txt", "wt");

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

	int arr[1000];
	int tmp, i = 0;

	while (1)
	{
		fscanf(fp.read, "%d", &tmp);

		if (!tmp)
			break;

		if (!(tmp % 5) && !(tmp % 3)) {
			arr[i++] = tmp;
		}
	}

	if (!i)
		fprintf(fp.write, "0");
	else
	{
		for (int j = 0; j < i; j++)
			fprintf(fp.write, "%d ", arr[j]);
		fprintf(fp.write, "\n%d", i);
	}

	_fcloseall();
	_getche();

	return 0;


}
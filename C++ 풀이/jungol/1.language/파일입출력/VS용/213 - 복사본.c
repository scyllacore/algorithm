#include <stdio.h>
#include <string.h>
#include <conio.h>

typedef struct msg {
	char s[100];
	int len;
}msg;

typedef struct file_rw
{
	FILE* read;
	FILE* write;
}file;

file fp;

int file_open()
{
	fp.read = fopen("input213.txt", "rt");
	fp.write = fopen("output213.txt", "wt");

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

	int i = 0, max;
	char str[100];
	char* ptr;
	msg m[100];

	fgets(str, 100, fp.read);
	fprintf(fp.write, "%d\n", strlen(str));

	ptr = strtok(str, " ");

	while (ptr)
	{
		strcpy(m[i].s, ptr);
		m[i].len = strlen(m[i].s);
		i++;
		ptr = strtok(NULL, " ");
	}

	max = m[0].len;
	for (int j = 0; j < i; j++)
	{
		if (max < m[j].len)
			max = m[j].len;
	}

	for (int j = 0; j < i; j++)
	{
		if (m[j].len == max)
			fprintf(fp.write, "%s ", m[j].s);
	}

	_fcloseall();
	_getche();

	return 0;


}
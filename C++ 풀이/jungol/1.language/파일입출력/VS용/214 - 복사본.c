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
	fp.read = fopen("input214.txt", "rt");
	fp.write = fopen("output214.txt", "wt");

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

    int n = 10;
    char a[10][100];
    char r[10][100];
    char tmp[20];
    char mark[2];

    int i, j, k;
    for (i = 0; i < n; i++) {
        fscanf(fp.read, "%s", a[i]);
    }
    fscanf(fp.read, "%s", mark);

    for (i = 0, j = 0; i < n; i++) {
        if (strstr(a[i], mark)) {
            strcpy(r[j], a[i]);
            j++;
        }
    }
    for (i = 0; i < j - 1; i++) {
        for (k = i + 1; k < j; k++) {
            if (strcmp(r[i], r[k]) > 0)
            {
                strcpy(tmp, r[i]);
                strcpy(r[i], r[k]);
                strcpy(r[k], tmp);
            }
        }
    }
    for (i = 0; i < j; i++) {
        fprintf(fp.write, "%s\n", r[i]);
    }

	_fcloseall();
	_getche();

	return 0;


}
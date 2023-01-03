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


/// 원하는 소스 추가


	_fcloseall();
	_getche();

	return 0;


}
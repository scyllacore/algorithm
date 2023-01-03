#include <stdio.h>
#include <conio.h>
# define SWAP(a,b) tmp = a; a = b; b = tmp

typedef struct file_rw
{
	FILE* read;
	FILE* write;
}file;

file fp;

int file_open()
{
	fp.read= fopen("input626.txt", "rt");
	fp.write = fopen("output626.txt", "wt");

	if (fp.read == NULL) {
		printf("파일열기 실패\n");
		return 0;
	}
	else {
		printf("파일열기 성공\n");
		return 1;
	}

}

int calculate(int num1, int num2)
{
	int sum = 0, tmp, i;
	if (num1 > num2)
	{
		SWAP(num1, num2);
	}

	for (i = num1; i <= num2; i++)
	{
		sum += i;
	}

	return sum;
}


int main()
{
	if (file_open() == 0) {
		_getche();
		return -1;
	}

	int num1, num2;

	fscanf(fp.read, "%d %d", &num1, &num2);
	fprintf(fp.write,"%d", calculate(num1,num2));

	_fcloseall();
	_getche();

	return 0;
}
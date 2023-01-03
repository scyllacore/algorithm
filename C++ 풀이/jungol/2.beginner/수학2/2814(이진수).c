#include <stdio.h> 
#include <stdlib.h>
#include <string.h>

int chk(char arr[]);

int main(void)

{

	int flag ,copy, result = 0, temp = 1;
	char binary[100];


	// 2진수를 입력합니다.

	printf("2진수 입력 : ");

	scanf("%s", binary);
	
	flag=chk(binary);

	while (1) {
		if (flag==0)
		{
			break;
		}
		else 
		{
			printf("잘못됨\n재입력 : ");
			scanf("%s", binary);
			flag = chk(binary);
		}
	}

	copy = atoi(binary);

	while (copy != 0)
	{

		if (copy % 10)

			result += temp;

		copy /= 10;

		temp *= 2;

	}



	// 결과 출력

	printf("이진수 %s는 십진수 %d입니다.\n", binary, result);
	return 0;
}


int chk(char arr[])
{
	int i, len, err=0;
	char chk[128] = { 0, };

	len = strlen(arr);

	for (i = 0; i < len; i++)
	{
		chk[arr[i]]++;
	}

	//아스키 코드를 이용한 검사

	for (i = 0; i < 47; i++) 
	{
		if (chk[i] != 0)
			err = 1;
	}

	for (i = 50; i < 127; i++)
	{
		if (chk[i] != 0)
			err = 1;
	}

	return err;
}
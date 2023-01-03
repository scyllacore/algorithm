#include <stdio.h>
#include <string.h>
int main()
{
	int len, i; //len=길이, i=반복 첨자의 변수
	int chk[255] = { 0, }; //배열을 0으로 초기화하여 선언
	char str[91]; //문장이 입력될 배열
	gets(str); //c언어 gets함수는 콘솔창에서 입력을 받는 함수로 문자열을 입력받음을 의미한다. 
	len = strlen(str); //문자열의 길이를 구해 len변수에 저장한다. 
	for (i = 0; i < len; i++) // 길이만큼 반복해 반복하여
	{
		chk[str[i]]++; //몇 번 들어갔는지 구한다.
	}

	for (i = 'a'; i <= 'z'; i++) //첫 번째 방법과 같은 부분으로, 모든 알파벳을 검사해 몇 번 들어갔는지 출력
	{
		if (chk[i] != 0) {
			printf("%c : ", i);
			for (int j = 0; j < chk[i]; j++) {
				printf("*");
			}
			printf("\n");
		}

	}
}

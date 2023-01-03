#include <stdio.h>
#include <string.h>
#include <ctype.h>

char key[26];///키
char message[100];///암호

void input() {
	scanf("%s ", key);///키를 입력 받는다; , 띄어쓰기는 getchar()의 역할
	//fgets(message, sizeof(message), stdin);///암호를 입력 받는다 , gets와 다르게 개행 문제도 읽음 , 한 줄 단위
	gets(message);

}
void check()
{
	int len = strlen(message);///len=문자열의 길이

	//message[--len] = '\0'; 

	for (int i = 0; i < len; i++) {///0~len
		if (isupper(message[i])) {///대문자라면?
			printf("%c",(char)toupper(key[message[i] - 'A']));
		}
		else if (islower(message[i])) 
				printf("%c",key[message[i] - 'a']);
		else 
				printf(" ");
	}
}

int main()
{
	input();///입력 함수 실행
	check();///암호 확인 함수 실행


	return 0;
}

//새로운 함수 소개 해주기 ctype.h ,is,to,
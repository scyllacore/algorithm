#include <stdio.h>
#include <string.h>


//정올에 있는 코드 복사 붙혀넣기 금지
//https://m.blog.naver.com/jsky10503/221133942782
//헤더파일 빼고 제출

int main(void) {

	char str1[] = "MY NAME IS HONGKILDONG"; // 포인터로 선언된 문자열은 값 변경이 안돼서 * -> []로 수정
	int len = strlen(str1);

	for (int i = 1; i < len; i++) {
		if (str1[i] != ' ') str1[i] += 32;
	}
	printf("%s\n", str1);

	char *str2 = malloc(sizeof(char)*(len+1)); // 동적할당으로 구현
	strcpy(str2, str1);

	for (int i = 1; i < len; i++) {
		if (str2[i] != ' ') str2[i] -= 32;
	}
	printf("%s\n", str2);
	return 0;

}


재 수정본

int main(void) {

	char str1[] = "MY NAME IS HONGKILDONG"; // 포인터로 선언된 문자열은 값 변경이 안돼서 * -> []로 수정
	int len = strlen(str1);

	for (int i = 1; i < len; i++) {
		if (str1[i] != ' ') str1[i] += 32;
	}
	printf("%s\n", str1);

	char *str2; // 동적할당으로 구현
	str2=str1;

	for (int i = 1; i < len; i++) {
		if (str2[i] != ' ') str2[i] -= 32;
	}
	printf("%s\n", str2);
	return 0;

}
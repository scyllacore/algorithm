#include <stdio.h>
#include <string.h> 

typedef struct word {
	char cutWord[201];
	int cntWord;
}Word;

Word words[201];
char str[201];

void set(int cnt); 
int cut(void); //단어로 끊어내는 함수 
void wordSort(int num); //알파벳 순으로 정렬하는 함수 

int main(void)
{
	int cnt = 0, i;

	while (1)
	{
		gets(str);

		if (strcmp(str, "END") == 0) //2.END가 입력되면 종료 
			return 0;

		cnt = cut();

		wordSort(cnt);

		for (i = 0; i < cnt; i++)
		{
			printf("%s : %d\n", words[i].cutWord, words[i].cntWord);
		}

		set(cnt);

	}

	return 0;
}


void set(int cnt)
{
	memset(str, 0, sizeof(str));
	memset(words, 0, cnt * sizeof(Word));

}


int cut(void)
{

	int i, newWord = 0, flag; //i: k, j:a, newWord : i, lenWord : j, flag: b

	char* ptr = strtok(str, " ");      // " " 공백 문자를 기준으로 문자열을 자름, 포인터 반환

	while (ptr != NULL)               // 자른 문자열이 나오지 않을 때까지 반복
	{
		flag = 0;

		for (i = 0; i < newWord; i++)
		{
			if (strcmp(ptr, words[i].cutWord) == 0)
			{
				words[i].cntWord++;
				flag = 1; //flag를 1로
				break;  // 그리고 멈춤
			}
		}
		if (flag == 0)
		{
			words[newWord].cntWord++;
			strcpy(words[newWord++].cutWord, ptr);
		}
		ptr = strtok(NULL, " ");      // 다음 문자열을 잘라서 포인터를 반환

	}

	return newWord;
}


void wordSort(int num)
{
	int i, j;
	Word temp;

	for (i = 0; i < num - 1; i++)
	{
		for (j = i + 1; j < num; j++)
		{
			if (strcmp(words[i].cutWord, words[j].cutWord) > 0)
			{
				temp = words[i];
				words[i] = words[j];
				words[j] = temp;
			}
		}

	}
}

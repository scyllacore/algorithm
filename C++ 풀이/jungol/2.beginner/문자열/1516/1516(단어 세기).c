#include <stdio.h>
#include <string.h> 

char word[201];
char cut_word[201][201];
char end[4] = { 'E', 'N', 'D', '\0' };
int cnt[201] = { 0 };

void set_word(void); //word 배열을 초기화하는 함수
void set_cut_word(int a); //cut_word 배열을 초기화하는 함수

int cut(void); //단어로 끊어내는 함수 
void line(int c); //알파벳 순으로 정렬하는 함수 
int what(int a, int b); //어떤 것이 앞 순서인지 판단하는 함수 

int main(void)
{
	int c = 0, i, k;

	while (1)
	{
		//scanf(" %[^\n]s", word);
		gets(word);

		c = cut();

		if (c == -1) //END가 입력되면 종료 
			break;

		line(c);

		for (i = 0; i < c; i++)
		{
			printf("%s : %d\n", cut_word[i], cnt[i]);
		}

		set_word();
		//strset(word, ' ');
		for (i = 0; i < c; i++)
		{
			set_cut_word(i);
			//strset(cut_word[i], ' ');
			cnt[i] = 0;
		}
	}

	return 0;
}
void set_word(void)
{
	int i = 0;
	while (word[i] != '\0')
	{
		word[i++] = ' ';
	}
	word[i] = ' ';
}

void set_cut_word(int a)
{
	int i = 0;
	while (cut_word[a][i] != '\0')
	{
		cut_word[a][i++] = ' ';
	}
	cut_word[a][i] = ' ';
}

int cut(void)
{
	int i = 0, j = 0, k, a, b;
	char temp[50];

	for (k = 0; ; k++)
	{
		if (word[k] == ' ' || word[k] == '\0')
		{
			temp[j] = '\0';

			if (strcmp(temp, end) == 0) //2.END가 입력되면 종료 
				return -1;

			else if (i > 0) // 4. 두번째 나오는 단어부터
			{
				b = 0;
				for (a = 0; a < i; a++) // 4-1. 단어가 전에 쓰였는지 확인
				{
					if (strcmp(temp, cut_word[a]) == 0) //4-2.전에 같은 단어가 있을 경우 
					{
						cnt[a]++; //그 단어의 cnt를 늘리고
						b = 1; //flag를 1로
						break;  // 그리고 멈춤
					}
				}
				if (b == 0) // 5. 같은 단어가 없을 시
				{
					cnt[i]++; // 그단어를 새로운 단어로 취급
					strcpy(cut_word[i++], temp); // 단어 복사
				}
			}

			else // 3. 처음에 나온 단어 처리
			{
				cnt[i]++;
				strcpy(cut_word[i++], temp);
			}

			if (word[k] == '\0') //입력된 문자열이 끝남 
				break;

			j = 0;
			k++;
		}

		if (word[k] != ' ') // 1. 띄어쓰기 전까지 temp에 저장
			temp[j++] = word[k];
	}

	return i;
}
void line(int c)
{
	int i, j, tmp, max;
	char temp[50];

	for (i = 0; i < c - 1; i++)
	{
		//max = i;
		//if (cut_word[i][0] != ' ') 
		//{
			for (j = i + 1; j < c; j++)
			{
				//if (what(max, j) == 1) //앞 단어가 더 뒷 순서일 경우 
				if (what(i, j) == 1)
				{
					//max = j;
					strcpy(temp, cut_word[i]);
					strcpy(cut_word[i], cut_word[j]);
					strcpy(cut_word[j], temp);

					tmp = cnt[i];
					cnt[i] = cnt[j];
					cnt[j] = tmp;
				}
			}

			/*if (max != i)
			{
				strcpy(temp, cut_word[i]);
				strcpy(cut_word[i], cut_word[max]);
				strcpy(cut_word[max], temp);

				tmp = cnt[i];
				cnt[i] = cnt[max];
				cnt[max] = tmp;
			}*/
		//}
	}
}
int what(int a, int b)
{
	int i;

	for (i = 0; ; i++)
	{
		if (cut_word[a][i] > cut_word[b][i] || cut_word[b][i] == '\0') // B와 A , AB 와 A -> 뒷 단어가 우선순위
		{
			return 1;
		}
		else if (cut_word[a][i] < cut_word[b][i] || cut_word[a][i] == '\0') // A와 B , A 와 AB -> 정상 순서
		{
			return 0;
		}
	}
}
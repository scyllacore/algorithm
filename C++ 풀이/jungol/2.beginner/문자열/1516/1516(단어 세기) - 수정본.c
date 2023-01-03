#include <stdio.h>
#include <string.h> 

typedef struct word {
    char cutWord[201];
    int cntWord;
}Word;

Word words[201];

char str[201];
char end[4] = "END";

void setCutWord(int numWord); //cut_word 배열을 초기화하는 함수
void setWord(int cnt); //word 배열을 초기화하는 함수

int cut(void); //단어로 끊어내는 함수 
void wordSort(int num); //알파벳 순으로 정렬하는 함수 
int what(int a, int b); //어떤 것이 앞 순서인지 판단하는 함수 

int main(void)
{
    int cnt = 0, i, k;

    while (1)
    {
        gets(str);

        if (strcmp(str, end) == 0) //2.END가 입력되면 종료 
            return 0;

        cnt = cut();


        wordSort(cnt);

        for (i = 0; i < cnt; i++)
        {
            printf("%s : %d\n", words[i].cutWord, words[i].cntWord);
        }

        setWord(cnt);
 
    }

    return 0;
}
void setWord(int cnt)
{
    int i = 0;
    while (str[i] != '\0')
    {
        str[i++] = ' ';
    }
    str[i] = ' ';

    for (i = 0; i < cnt; i++)
    {
        setCutWord(i);
        words[i].cntWord = 0;
    }
}

void setCutWord(int numWord)
{
    int i = 0;
    while (words[numWord].cutWord[i] != '\0')
    {
        words[numWord].cutWord[i++] = ' ';
    }
    words[numWord].cutWord[i] = ' ';
}

int cut(void)
{
    //i: k, j:a, newWord : i, lenWord : j, flag: b
    int i, j, newWord = 0, lenWord = 0, flag;
    char temp[50];

    for (i = 0; ; i++)
    {
        if (str[i] == ' ' || str[i] == '\0')
        {
            temp[lenWord] = '\0';



            if (newWord > 0) // 4. 두번째 나오는 단어부터
            {
                flag = 0;
                for (j = 0; j < newWord; j++) // 4-1. 단어가 전에 쓰였는지 확인
                {
                    if (strcmp(temp, words[j].cutWord) == 0) //4-2.전에 같은 단어가 있을 경우 
                    {
                        words[j].cntWord++; //그 단어의 cnt를 늘리고
                        flag = 1; //flag를 1로
                        break;  // 그리고 멈춤
                    }
                }
                if (flag == 0) // 5. 같은 단어가 없을 시
                {
                    words[newWord].cntWord++; // 그단어를 새로운 단어로 취급
                    strcpy(words[newWord++].cutWord, temp); // 단어 복사
                }
            }

            else // 3. 처음에 나온 단어 처리
            {
                words[newWord].cntWord++;
                strcpy(words[newWord++].cutWord, temp);
            }

            if (str[i] == '\0') //입력된 문자열이 끝남 
                break;

            lenWord = 0;
            i++;
        }

        if (str[i] != ' ') // 1. 띄어쓰기 전까지 temp에 저장
            temp[lenWord++] = str[i];
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
            if (what(i, j) == 1)
            {
                temp = words[i];
                words[i] = words[j];
                words[j] = temp;
            }
        }

    }
}

int what(int a, int b)
{
    int i;

    for (i = 0; ; i++)
    {
        if (words[a].cutWord[i] > words[b].cutWord[i] || words[b].cutWord[i] == '\0') // B와 A , AB 와 A -> 뒷 단어가 우선순위
        {
            return 1;
        }
        else if (words[a].cutWord[i] < words[b].cutWord[i] || words[a].cutWord[i] == '\0') // A와 B , A 와 AB -> 정상 순서
        {
            return 0;
        }
    }
}
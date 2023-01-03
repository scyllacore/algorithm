#include <stdio.h>

char nume[36];

unsigned long long changePre(char t[], int numeral);
void changePost(unsigned long long n, int b);
void initialization(char num[]);


int main()
{
    int preNumeral, postNumeral;
    unsigned long long numFirst;
    char num[100];

    initialization(nume);


    for (;;) {
        scanf("%d", &preNumeral);

        if (preNumeral == 0)
            break;

        scanf(" %s %d", num, &postNumeral);


        numFirst = changePre(num, preNumeral); // 어떤 진법의 숫자를 10진법으로 변환

        if (numFirst == 0 || numFirst == 1) {
            printf("%lld\n", numFirst);
            continue;
        }

        changePost(numFirst, postNumeral); // 10진법 된 숫자를 원하는 진법으로 변환
        printf("\n");
        //puts("");
    }


}

void initialization(char num[])
{
    int i,cnt=0;
    for (i = 48; i <= 57; i++)
    {
        num[cnt++] = i;
    }

    for (i = 65; i <= 90; i++)
    {
        num[cnt++] = i;
    }
}


unsigned long long changePre(char t[], int numeral)
{
    int i, len;
    unsigned long long ten = 0;
    len = strlen(t);
    for (i = 0; i < len; i++)
    {
        if (t[i] <= 57)
            ten = ten * numeral + (t[i] - 48);  //앞자리까지의 값에 2를 곱하고 현재의 값을 더한다.
        else if (t[i] <= 90)
            ten = ten * numeral + (t[i] - 55);
    }
    return ten;
}

void changePost(unsigned long long n, int b) //십진수 n을 b진수로 
{
    if (n != 0)
    {
        changePost(n / b, b);
        printf("%c", nume[n % b]);
    }

}
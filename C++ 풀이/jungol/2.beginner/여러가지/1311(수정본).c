#include <stdio.h>
#include <stdlib.h>


typedef struct card {
    char color;
    int num;
}Card;

int cardListNum[10];

int compareColor(Card  slectCard[]);
int compareNum(Card  slectCard[]);
void listsameNum(Card  slectCard[], int* flag1, int* flag2);


int main() {
    int i, sameColor, sucsNum;
    int flag1 = 1, flag2 = 1;
    Card slectCard[5];

    for (i = 0; i < 5; i++)
    {
        scanf(" %c %d", &slectCard[i].color, &slectCard[i].num);
    }

    sameColor = compareColor(slectCard);
    sucsNum = compareNum(slectCard);
    listsameNum(slectCard, &flag1, &flag2);

    if (sameColor == 5 && sucsNum == 5) //1. 카드 5장이 모두 같은 색이면서 숫자가 연속적일 때 
        printf("%d", slectCard[4].num + 900);

    else if (sameColor == 5) //4. 카드 5장이 모두 같은 색일 때 
        printf("%d", slectCard[4].num + 600);

    else if (sucsNum == 5) //5. 카드 5장의 숫자가 연속적일 때 
        printf("%d", slectCard[4].num + 500);

    else
    {

        if (cardListNum[flag1] == 4) //2. 카드 4장의 숫자가 같을 때 
            printf("%d", flag1 + 800);

        else if (cardListNum[flag1] == 3)
        {
            if (cardListNum[flag2] == 2) //3. 카드 3장의 숫자가 같고 나머지 2장도 숫자가 같을 때 
                printf("%d", (flag1 * 10) + flag2 + 700);

            else //6. 카드 3장의 숫자가 같을 때 
                printf("%d", flag1 + 400);
        }

        else if (cardListNum[flag1] == 2)
        {
            if (cardListNum[flag2] == 2) { //7. 카드 2장의 숫자가 같고 또 다른 2장의 숫자가 같을 때 
                if (flag1 > flag2) printf("%d", (flag1 * 10) + flag2 + 300);
                else  printf("%d", (flag2 * 10) + flag1 + 300);
            }
            else //8. 카드 2장의 숫자가 같을 때 
                printf("%d", flag1 + 200);
        }
        else //어떤 경우도 해당하지 않을 때 
            printf("%d", slectCard[4].num + 100);

    }


}

int compareColor(Card  slectCard[])
{
    int i;

    for (i = 1; i < 5; i++)
    {
        if (slectCard[0].color != slectCard[i].color)
            return 0;
    }

    return 5;
}


int compareNum(Card  slectCard[]) {

    int i, j;
    Card tmp;

    for (i = 0; i < 4; i++)
        for (j = i + 1; j < 5; j++)
            if (slectCard[i].num > slectCard[j].num)
            {
                tmp = slectCard[i];
                slectCard[i] = slectCard[j];
                slectCard[j] = tmp;
            }

    for (i = 0; i < 4; i++) //숫자가 연속적인가? 
    {
        if (slectCard[i].num + 1 != slectCard[i + 1].num)
            return 0;
    }

    return 5;

}

void listsameNum(Card  slectCard[], int* flag1, int* flag2)
{
    int i, j;
    int max1 = -999, max2 = -999;


    for (i = 0; i < 5; i++)
    {
        cardListNum[slectCard[i].num]++;
    }

    for (i = 1; i < 10; i++)
    {
        if (max1 < cardListNum[i]) {
            max1 = cardListNum[i];
            *flag1 = i;
        }
    }

    for (i = 1; i < 10; i++)
    {
        if (i == *flag1)
            continue;


        if (max2 < cardListNum[i]) {
            max2 = cardListNum[i];
            *flag2 = i;
        }
    }
}


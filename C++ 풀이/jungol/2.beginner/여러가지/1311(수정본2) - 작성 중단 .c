#include <iostream>
#include <map>

using namespace std;

struct Card{
    char color;
    int num;
};

int cardListNum[10];

int compareColor(Card  slectCard[]);
int compareNum(Card  slectCard[]);
void listsameNum(Card  slectCard[], int* flag1, int* flag2);


int main() {

    int i;
    int flag1 = 1, flag2 = 1;
    map<int,char> selectCard;
    char color;
    int num;

    for (i = 0; i < 5; i++)
    {
        cin >> color >> num;
        selectCard[num] = color;
    }

    bool sameColor = compareColor(selectCard);
    bool sucsNum = compareNum(selectCard);

    listsameNum(selectCard, &flag1, &flag2);

    if (sameColor && sucsNum) //1. 카드 5장이 모두 같은 색이면서 숫자가 연속적일 때 
        printf("%d", slectCard[4].num + 900);

    else if (sameColor) //4. 카드 5장이 모두 같은 색일 때 
        printf("%d", slectCard[4].num + 600);

    else if (sucsNum) //5. 카드 5장의 숫자가 연속적일 때 
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

bool compareColor(map<int, char>& slectCard)
{
    int i;

    char color = slectCard.begin()->second;

    for (auto comp : slectCard)
    {
        if (color != comp.second) return 0;
    }

    return 1;
}


bool compareNum(map<int, char>& selectCard) {
    return selectCard.size() == 5 ? 1 : 0;
}

void listsameNum(map<int, char>& selectCard)
{

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


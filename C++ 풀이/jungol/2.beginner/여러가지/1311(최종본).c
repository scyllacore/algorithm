#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Card {
    char color;
    int num;
};

struct numInfo{
    int idx;
    int cnt;
};

vector<numInfo> nInfo;

bool cmpCard(const Card& a, const Card& b) {
    return a.num > b.num;
}

bool cmpCnt(const numInfo& a, const numInfo& b) {
    return a.cnt > b.cnt;
}

bool compareColor(vector<Card>& slectCard)
{
    for (int i = 1; i < 5; i++)
    {
        if (slectCard[0].color != slectCard[i].color)
            return 0;
    }
    return 1;
}


bool compareNum(vector<Card>& slectCard) {

    sort(slectCard.begin(), slectCard.end(), cmpCard);

    for (int i = 0; i < 4; i++)
    {
        if (slectCard[i].num - 1 != slectCard[i + 1].num)
            return 0;
    }
    return 1;

}

void listsameNum(vector<Card>& slectCard)
{
    int i;
    int cardListNum[10] = { 0 };

    for (i = 0; i < 5; i++)
    {
        cardListNum[slectCard[i].num]++;
    }

    for (i = 0; i < 10; i++)
    {
        if (cardListNum[i]) {
            nInfo.push_back({ i,cardListNum[i] });
        }
    }
    sort(nInfo.begin(), nInfo.end(), cmpCnt);

}

int main() {
    int i;
    vector<Card> slectCard(5);

    for (i = 0; i < 5; i++)
    {
       cin >> slectCard[i].color >> slectCard[i].num;
    }

    bool sameColor = compareColor(slectCard);
    bool sucsNum = compareNum(slectCard);
    listsameNum(slectCard);

    if (sameColor && sucsNum) //1. 카드 5장이 모두 같은 색이면서 숫자가 연속적일 때 
        cout << slectCard[0].num + 900;

    else if (sameColor) //4. 카드 5장이 모두 같은 색일 때 
        cout << slectCard[0].num + 600;

    else if (sucsNum) //5. 카드 5장의 숫자가 연속적일 때 
       cout << slectCard[0].num + 500;

    else
    {
        if (nInfo[0].cnt == 4) //2. 카드 4장의 숫자가 같을 때 
            cout <<  nInfo[0].idx + 800;

        else if (nInfo[0].cnt == 3)
        {
            if (nInfo[1].cnt == 2) //3. 카드 3장의 숫자가 같고 나머지 2장도 숫자가 같을 때 
                cout << (nInfo[0].idx * 10) + (nInfo[1].idx + 700);

            else //6. 카드 3장의 숫자가 같을 때 
               cout << nInfo[0].idx + 400;
        }

        else if (nInfo[0].cnt == 2)
        {
            if (nInfo[1].cnt == 2) { //7. 카드 2장의 숫자가 같고 또 다른 2장의 숫자가 같을 때 
                if (nInfo[0].idx > nInfo[1].idx) cout << (nInfo[0].idx * 10) + (nInfo[1].idx + 300);
                else cout << (nInfo[1].idx * 10) + nInfo[0].idx + 300;
            }
            else //8. 카드 2장의 숫자가 같을 때 
                cout << nInfo[0].idx + 200;
        }
        else //어떤 경우도 해당하지 않을 때 
            cout << slectCard[0].num + 100;

    }

    return 0;

}



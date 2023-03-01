#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int cardBox[101] = { 0 };

int getOneGroupCardCount(int start) {

    int count = 0;
    int next = start;


    for (; cardBox[next] != 0;) {
        count++;

        int tmpNext = cardBox[next];
        cardBox[next] = 0;
        next = tmpNext;
    }

    return count;
}


int solution(vector<int> cards) {

    int size = cards.size();

    for (int i = 1; i <= size; i++) {
        cardBox[i] = cards[i - 1];
    }

    vector<int> answerCount;

    for (int i = 1; i <= size; i++) {
        if (!cardBox[i]) {
            continue;
        }

        int count = getOneGroupCardCount(i);
        answerCount.push_back(count);
    }

    if (answerCount.size() < 2) {
        return 0;
    }

    sort(answerCount.begin(), answerCount.end(), greater<>());

    return answerCount[0] * answerCount[1];
}
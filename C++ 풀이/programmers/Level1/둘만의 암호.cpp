#include <string>
#include <vector>

using namespace std;

bool alpha[26] = { 0 };

char getAlphaBySkip(char startCh, int endCnt) {

    int cnt = 0;
    int startIdx = startCh - 'a' + 1;
    int i;

    for (i = startIdx; cnt != endCnt; i++) {
        if (!alpha[i % 26]) {
            cnt++;
        }
    }

    return 'a' + ((i - 1) % 26); //  'a'+ (i%26) - 1;
    //시작을 무조건 'a'에서 하도록 해야하는데 'a' - 1 이면 'a'이전에서 시작하는 것임.
    //따라서 위치에 관여하는 i에다가 직접 -1을 해줘야지 정상적으로 a에서 시작할 수 있음.
}

string solution(string s, string skip, int index) {
    for (char ch : skip) {
        alpha[ch - 'a'] = 1;
    }

    for (char& ch : s) {
        ch = getAlphaBySkip(ch, index);
    }

    return s;
}
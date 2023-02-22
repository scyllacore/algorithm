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
    //������ ������ 'a'���� �ϵ��� �ؾ��ϴµ� 'a' - 1 �̸� 'a'�������� �����ϴ� ����.
    //���� ��ġ�� �����ϴ� i���ٰ� ���� -1�� ������� ���������� a���� ������ �� ����.
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
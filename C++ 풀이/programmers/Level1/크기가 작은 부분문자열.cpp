#include <string>
#include <vector>

using namespace std;

int solution(string t, string p) {
    int answer = 0;

    for (int i = 0; i <= t.length() - p.length(); i++) {
        string tSub = t.substr(i, p.length());

        if (tSub.compare(p) <= 0) {
            answer++;
        }

    }

    return answer;
}

/*
int answer = 0;
    int pVal = stoi(p);

    for(int i=0; i<=t.length()-p.length(); i++){
        int tVal=stoi(t.substr(i,p.length()));
        // ���ڰ� �ſ� ū ���̱� ������ ���� �ڷ����� ���� �� ����.
        if(tVal<=pVal){
            answer++;
        }

    }

    return answer;
*/
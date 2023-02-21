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
        // 숫자가 매우 큰 값이기 때문에 숫자 자료형에 담을 수 없다.
        if(tVal<=pVal){
            answer++;
        }

    }

    return answer;
*/
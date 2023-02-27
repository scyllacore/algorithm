#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

bool checkSameCnt(unordered_map<string, int>& aMap, unordered_map<string, int>& bMap) {
    for (auto a : aMap) {
        if (aMap[a.first] != bMap[a.first]) {
            return 0;
        }
    }

    return 1;
}

int solution(vector<string> want, vector<int> number, vector<string> discount) {

    unordered_map<string, int> wantCnt;

    int i, j;

    for (i = 0; i < want.size(); i++) {
        wantCnt[want[i]] = number[i];
    }

    unordered_map<string, int> disCnt;


    for (i = 0; i < 10; i++) {
        disCnt[discount[i]]++;
    }

    int answer = 0;

    for (i = 10; i < discount.size(); i++) {
        if (checkSameCnt(wantCnt, disCnt)) {
            answer++;
        };

        disCnt[discount[i]]++;
        disCnt[discount[i - 10]]--; // Q를 쓰지 않아도 된다.

    }

    if (checkSameCnt(wantCnt, disCnt)) {
        answer++;
    };

    return answer;
}

/*
#include <string>
#include <vector>
#include <unordered_map>
#include <queue>

using namespace std;

bool checkSameCnt(unordered_map<string,int>& aMap, unordered_map<string,int>& bMap){
    for(auto a : aMap){
        if(aMap[a.first] != bMap[a.first]){
            return 0;
        }
    }

    return 1;
}

int solution(vector<string> want, vector<int> number, vector<string> discount) {

    unordered_map<string,int> wantCnt;

    int i,j;

    for(i=0; i<want.size(); i++){
        wantCnt[want[i]] = number[i];
    }

    queue<string> disQ;
    unordered_map<string,int> disCnt;


    for(i=0; i<10; i++){
        disQ.push(discount[i]);
        disCnt[discount[i]]++;
    }

    int answer=0;

    for(i=10; i<discount.size(); i++){
        if(checkSameCnt(wantCnt,disCnt)){
            answer++;
        };

        disCnt[discount[i]]++;
        disCnt[disQ.front()]--;

        disQ.push(discount[i]);
        disQ.pop();
    }

    if(checkSameCnt(wantCnt,disCnt)){
        answer++;
    };

    return answer;
}
*/
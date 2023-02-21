#include <string>
#include <vector>

using namespace std;

vector<int> solution(string s) {
    vector<int> answer(s.size(), -1);

    vector<int> alpha(26, -1);

    for (int i = 0; i < s.size(); i++) {
        if (alpha[s[i] - 'a'] != -1) {
            answer[i] = i - alpha[s[i] - 'a'];
        }

        alpha[s[i] - 'a'] = i; // 알파벳에 대한 위치를 계속해서 갱신시키는 형태의 방법.
    }

    return answer;
}

/*
 for(int i=0; i<s.size(); i++){
        for(int j=i-1; j>=0; j--){
           if(s[i] == s[j]){
               answer[i] = i-j;
               break;
           }
        }
    }
*/
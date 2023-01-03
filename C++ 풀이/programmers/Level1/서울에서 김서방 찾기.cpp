#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string solution(vector<string> seoul) {
    string answer;
    
    int pos = find(seoul.begin(),seoul.end(),"Kim")-seoul.begin();
    answer = "김서방은 " + to_string(pos) + "에 있다";
    return answer;
}

/*
int pos,i;
    int size = seoul.size();
    
    for(pos=0; pos<size; pos++){
        if(!seoul[pos].compare("Kim")){
            answer += "김서방은 ";
            answer += to_string(pos);
            answer += "에 있다";
            break;
        }
    }  
    
    return answer;
*/
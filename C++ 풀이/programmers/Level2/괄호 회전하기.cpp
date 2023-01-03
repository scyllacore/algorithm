#include <string>
#include <vector>
#include <deque>

using namespace std;

bool checkPair(char front,char back){
    if(front == '(' && back == ')') return 1;
    else if(front == '{' && back == '}') return 1;
    else if(front == '[' && back == ']') return 1;
    else return 0;
}

bool checkVPS(deque<char>& VPS){
    
    int i;
    
    deque<char> dq;
    
    for(i=0; i<VPS.size(); i++){      
        if(!dq.empty() && checkPair(dq.back(),VPS[i])){dq.pop_back();}
        else{dq.push_back(VPS[i]);} 
    }
    
    return !(dq.size());
    
}

int solution(string s) {
    
    deque<char> str;
    
    for(auto ch : s){
        str.push_back(ch);
    }
    
    int answer=0,i;
    
    for(i=0; i<str.size()-1; i++){
        
        deque<char> VPS(str);
        
       if(checkVPS(VPS)) answer++;
        
        str.push_back(str.front());
        str.pop_front();
          
    }
    
    return answer;
    
}
/*
#include <string>
#include <vector>
#include <deque>

using namespace std;

bool checkVPS(deque<char>& VPS){

    int i;

    deque<char> dq;

    for(i=0; i<VPS.size(); i++){

        if(!dq.empty() && VPS[i] == ']' && dq.back() == '['){
            dq.pop_back();
            continue;
           }
        if(!dq.empty() && VPS[i] == ')' && dq.back() == '('){
            dq.pop_back();
            continue;
           }
        if(!dq.empty() && VPS[i] == '}' && dq.back() == '{'){
            dq.pop_back();
            continue;
         }     
        dq.push_back(VPS[i]);    
    }

    return !(dq.size());

}

int solution(string s) {

    deque<char> str;

    for(auto ch : s){
        str.push_back(ch);
    }

    int answer=0,i;

    for(i=0; i<str.size()-1; i++){

        deque<char> VPS(str);

       if(checkVPS(VPS)) answer++;

        str.push_back(str.front());
        str.pop_front();

    }

    return answer;

}
*/
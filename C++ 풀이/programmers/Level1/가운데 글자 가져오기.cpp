#include <string>
#include <vector>

using namespace std;

string solution(string s) {
    
    int len = s.length();   
    string answer = "";
    
    if(len%2 == 1){
        answer += s[len/2];
        //return s.substr(len/2,1);
    }
    else{
       answer += s[len/2-1]; 
        answer += s[len/2];
        //return s.substr(len/2-1,2);
    }
    
    return answer;
}

/*
string solution(string s) {
    int len = s.length();
    if(len%2==0){
        return s.substr(len/2-1,2);
    }
    else {
            return s.substr(len/2,1);
        }
}

*/
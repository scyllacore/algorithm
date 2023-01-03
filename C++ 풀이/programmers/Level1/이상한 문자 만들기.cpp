#include <string>
#include <vector>
//#include <sstream>
#include <cctype>

using namespace std;

string solution(string s) {

    int len = s.length();
    int i,idx=0;
    
    for(i=0; i<len; i++){
        
        if(s[i] == ' '){
            idx=0;
        }
        else if(idx%2 == 0){
            if(islower(s[i])) s[i] -= 32;
            idx++;
        }
        else if(idx%2 == 1){
            if(isupper(s[i])) s[i] += 32;
            idx++;
        }
        
    }
    
    return s;
    
}

/*
 istringstream iss(s);
    vector<string> word;
    
    string tmp;
    
    for(;(iss>>tmp);){
        word.push_back(tmp);
    }
    
    int size=word.size();
    int wordLen;
    int i,j;
    
     for(i=0; i<size; i++){
         wordLen = word[i].length();
        for(j=0; j<wordLen; j+=2){
            if(islower(word[i][j])){
            word[i][j] -= 32;}
            
        }
        for(j=1; j<wordLen; j+=2){
            if(isupper(word[i][j])){
            word[i][j] += 32;
        }
        }
    }   
    
    string answer = "";
    
    for(i=0; i<size; i++){
        answer += word[i] + ' ';
    }       
    answer.pop_back();
    return answer;
    
    왜 안되는지 이유 찾아야 함.
    sol : 공백이 여러개 있을 수도 있다고 했다. 그러나 위 코드에서는 무조건 단어사이의 공백을 하나로 만든다. 
          따라서 원래 문자열과 길이가 다르게 나올 수 있기 때문에 안된다.
*/
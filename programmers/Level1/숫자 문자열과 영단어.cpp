#include <string>
#include <vector>
#include <cctype>

using namespace std;

int solution(string s) {
    
    string numWord[10] ={"zero","one","two","three","four","five","six","seven","eight","nine"};
    string answer;
    
    
    for(int i=0; i<s.length();){
        if(isdigit(s[i])){
            answer+=s[i++];
        }
        else{
            for(int j=0; j<10; j++){
                if(!s.compare(i,numWord[j].length(),numWord[j],0,numWord[j].length())){
                    //(s 시작점 , s 길이 , 비교할 대상 , 비교할 대상 시작점 , 비교할 대상 길이)
                    answer+= (j+'0');
                    i += numWord[j].length();
                    break;
                }
            }
        }
    }
    
    return stoi(answer);
    
}

/*
for(int i=0; i<s.length();){
        if(isdigit(s[i])){
            answer+=s[i++];
        }
        else{
            for(int j=0; j<10; j++){
                if(s.find(numWord[j],i)!=string::npos){
                    answer+= (j+'0');
                    i += numWord[j].length();
                    break;
                }
            }
        }
    }
*/

/*
#include <string>
#include <vector>

using namespace std;

int solution(string s) {
    int answer = 0;
    int i;
    
    for(int i=0; i<s.length(); i++){
        if(s[i] >= '0' && s[i] <= '9'){
            answer = answer*10 + (s[i]-'0');
        }
        else{
            if(s[i]=='z' && s[i+1]=='e'){
                answer = answer*10;
                i+=3;
            }
            else if(s[i]=='o'){
                answer = answer*10 +1;
                i+=2;
            }
            else if(s[i]=='t'&& s[i+1]=='w'){
                answer = answer*10 +2;
                i+=2;
            }
            else if(s[i]=='t'&& s[i+1]=='h'){
                answer = answer*10 +3;
                i+=4;
            }
            else if(s[i]=='f'&& s[i+1]=='o'){
                answer = answer*10 +4;
                i+=3;
            }
            else if(s[i]=='f'&& s[i+1]=='i'){
                answer = answer*10 +5;
                i+=3;
            }
            else if(s[i]=='s' && s[i+1]=='i'){
                answer = answer*10 +6;
                i+=2;
            }
            else if(s[i]=='s' && s[i+1]=='e'){
                answer = answer*10+7;
                i+=4;
            }
            else if(s[i]=='e'){
                answer = answer*10 +8;
                i+=4;
            }
            else if(s[i]=='n'){
                answer = answer*10 +9;
                i+=3;
            }
        }
        
    }
    
    return answer;
}
*/
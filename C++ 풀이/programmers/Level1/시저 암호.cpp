#include <string>
#include <vector>
#include <cctype>

using namespace std;

string solution(string s, int n) {
    
    int len=s.length();
    int i;
    char ch;
    
        
    string answer = "";
    
    for(i=0; i<len; i++){
        if(isupper(s[i])){
            ch = (s[i]-'A'+n)%26 + 'A';
        }
        else if(islower(s[i])){
             ch = (s[i]-'a'+n)%26 + 'a';
        }
        else{
            ch = ' ';
        }
        answer += ch;
    }
    
    return answer;
}
#include <string>
#include <vector>
#include <algorithm>
#include <cctype>

using namespace std;

string solution(string s) {
    
    transform(s.begin(),s.end(),s.begin(),::tolower);
    
    if(islower(s[0])){s[0] -= 32;}
    
    for(int i=0; i<s.length(); i++){
        if(isspace(s[i]) && islower(s[i+1])){
            s[i+1] -= 32;
        }
    }
    
    return s;
}
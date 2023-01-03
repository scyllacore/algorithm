#include <string>
#include <algorithm>
#include <vector>

using namespace std;

string ternary(int n){
    
    string numStr = "";
    
    while(n>0){
        numStr += (n%3) + '0';
        n/=3;
    }
    
    return numStr;
    
}

int solution(int n) {
     
    int answer = 0,i;
    
    string numStr = ternary(n);
    
    for(i=0; i<numStr.length(); i++){
        answer = answer*3 + (numStr[i] - '0');
    }
    
    return answer;
}
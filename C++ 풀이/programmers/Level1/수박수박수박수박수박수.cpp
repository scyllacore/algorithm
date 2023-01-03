#include <string>
#include <vector>

using namespace std;

string solution(int n) {
    
    int i;
    
    string answer = "";
    
    for(i=0; i<n/2; i++){
        answer += "수박";
    }
    
    if(n%2 == 1){ answer += "수"; }
    
    return answer;
}
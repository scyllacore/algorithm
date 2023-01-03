#include <string>
#include <vector>
#include <algorithm>

using namespace std;

long long solution(int a, int b) {
    long long answer = 0;
    
    int i;
    
    if(a>b){
        swap(a,b);
    }
    
    for(i=a; i<=b; i++){
        answer += i;
    }
    
    
    return answer;
}
#include <string>
#include <vector>

using namespace std;

int getNum(long long n){
    
    for(int i=2; i<=n/i; i++){
        if(n%i==0 && n/i <= (int)1e7){
            return n/i;
        }
    }
    return 1;
}

vector<int> solution(long long begin, long long end) {
    vector<int> answer;
    
    if(begin==1) {answer.push_back(0),begin=2;}
    
    for(long long i=begin; i<=end; i++){
        int n = getNum(i);
        answer.push_back(n);
    }
    
    return answer;
}
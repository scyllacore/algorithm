#include <string>
#include <vector>

using namespace std;

bool solution(int x) {
    
    int n=x;
    int sum=0;
    
    for(;n>0;){
        sum += (n%10);
        n/=10;
    }
    
    return x%sum==0? 1:0;
}
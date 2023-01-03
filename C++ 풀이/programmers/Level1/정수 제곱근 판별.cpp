#include <string>
#include <vector>

using namespace std;

long long solution(long long n) {
    
    long long i;
    
    for(i=1; i*i<=n; i++){
        if(i*i==n){ // -> 10/3은 3으로 계산됨. 반례가 존재함으로 나누기로 제곱수를 구할 수 없다
            return (i+1)*(i+1);
        }
    }
    return -1;
}
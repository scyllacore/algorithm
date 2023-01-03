#include <string>
#include <vector>

using namespace std;

int solution(int num) {
    int cnt;
    
    long long n = num;
    
    for(cnt=0; cnt<501; cnt++){
       
        if(n==1){  return cnt; }
      
        if(n%2==0){n/=2;}
        else{n = n*3+1;}     
    }
    
    return -1;
}
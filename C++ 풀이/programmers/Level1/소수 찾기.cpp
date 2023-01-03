#include <string>
#include <vector>

using namespace std;

bool prime[1000001]={0};

void eratos(int n){
    
    int i,j;
    
    for(i=2; i<=n/i; i++){    
        if(!prime[i]){
            for(j=i*i; j<=n; j+=i){
                prime[j]= 1;
            }
        }   
    }
    
}

int solution(int n) {
    int answer = 0,i;
    
    eratos(n);
    
    for(i=2; i<=n; i++){
        if(!prime[i]) answer++;
    }
    
    return answer;
}
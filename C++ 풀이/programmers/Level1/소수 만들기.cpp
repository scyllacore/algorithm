#include <vector>
#include <iostream>
using namespace std;

bool isPrime(int n){
    
    int i;
    
    for(i=2; i<= n/i; i++){
        if(n%i == 0){
            return 0;
        }
    }
    
    return 1;
}

int solution(vector<int> nums) {
    int answer = 0;
    int size = nums.size();
    int i,j,k;
    int sum;
    
    
    for(i=0; i<size-2; i++){
        for(j=i+1; j<size-1; j++)
        {
            
            for(k=j+1; k<size; k++){
                sum= nums[i] +   nums[j] + nums[k];
                
                if(isPrime(sum)){answer++;}
                
            }
        }
        
    }

    return answer;
}
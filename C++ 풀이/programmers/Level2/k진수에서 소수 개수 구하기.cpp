#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

string notation = "0123456789";

bool isPrime(string numStr,int k){
  long long num=0,i;
  int len = numStr.length();
    
  for(i=0; i<len; i++){
      num = num*10 + numStr[i] -'0';
  }
   
  if(num==1 || num == 0) return 0;  
    
  for(i=2; i<=num/i; i++){
      if(num%i ==0) return 0;
  } 
    
  return 1;  

}

int solution(int n, int k) {
    
    string cvtNum;  
    while(n>0){
        cvtNum += notation[n % k];
        n/=k;   
    }
    
    reverse(cvtNum.begin(),cvtNum.end());
    
    int answer = 0;
    
    string numStr="";
    
    for(auto cN : cvtNum){
        
        if(cN == '0'){          
            if(isPrime(numStr,k)){
                answer++;
            }      
            numStr ="";
        }
        else{
           numStr += cN; 
        }  
    }
      
    if(isPrime(numStr,k)){
         answer++;
    }   
    
    return answer;
}

/*
#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

#define MAX 1000001

string notation = "0123456789";
bool prime[MAX];

void eratos(int n){
    
    fill_n(prime,MAX,0);
    prime[0]=prime[1] = 1;
    
    int i,j;
    
    for(i=2; i<=n/i; i++){
        
        if(!prime[i]){
            for(j=i*i; j<n; j+=i){
                prime[j] = 1;
            }
        }
    }
       
}

bool isPrime(string numStr,int k){
  int num=0;
  int len = numStr.length();
    
  for(int i=0; i<len; i++){
      num = num*10 + numStr[i] -'0';
  }

 if(!prime[num]){
     return 1;
  }else{
     return 0;
 }

}

int solution(int n, int k) {
    
    eratos(n);
    
    string cvtNum;
    
    while(n>0){
        cvtNum += notation[n % k];
        n/=k;   
    }
    
    reverse(cvtNum.begin(),cvtNum.end());
    
    int answer = 0;
    
    string numStr="";
    
    for(auto cN : cvtNum){
        
        if(cN == '0'){
                 
            if(isPrime(numStr,k)){
                answer++;
            }      
            numStr ="";
        }
        else{
           numStr += cN; 
        }  
    }
      
    if(isPrime(numStr,k)){
         answer++;
    }   
    
    return answer;
}

*/
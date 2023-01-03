#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

int solution(int n, int a, int b)
{
    int i;
    
   for(i=1; i<n; i++){
        if(a%2==1){a++;}
        if(b%2==1){b++;}    
        a/=2,b/=2;
       
       if(a==b){break;}
       
    }
    
    
    /*
    my code
    while(abs(a-b) !=1){
        if(a%2==1){a++;}
        if(b%2==1){b++;}    
        a/=2,b/=2;
        answer++;
    }
    
    a=4,b=5일 때 안됨
    
    */
    
    return i;
}
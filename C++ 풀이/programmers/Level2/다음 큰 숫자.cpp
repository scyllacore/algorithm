#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(int n) {
    
    int i,j;
    int curOneCnt=0;
    
    for(i=0; (1<<i) < n; i++){
        if(n&(1<<i)){curOneCnt++;}
    }
      
    int nextOneCnt;
    
    for(i=n+1; i<20000000 ;i++){
        
        nextOneCnt=0;
        
        for(j=0; (1<<j)<i; j++){
        if(i&(1<<j)){nextOneCnt++;}}
        
        if(curOneCnt == nextOneCnt){return i;}
    }

}
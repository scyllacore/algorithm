#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

char notation[16] = {'0','1','2','3','4','5','6','7','8','9','A','B','C','D','E','F'};

string solution(int n, int t, int m, int p) {
    
    string gameNum="0";  
    int i;
    
    for(i=1; gameNum.length() < t*m; i++){
        
        int tmpN = i;
        string tmpStr;
        
        while(tmpN>0){
            tmpStr += notation[tmpN%n];
            tmpN /= n;
        }
        
        reverse(tmpStr.begin(),tmpStr.end());
        
        gameNum += tmpStr;
        
    }
    
    //cout << gameNum << '\n';
    
    string answer = "";
    int idx = p-1;
    
    for(i=0; i<t; i++){
        answer += gameNum[idx];
        idx += m;  
    }
    
    return answer;
}
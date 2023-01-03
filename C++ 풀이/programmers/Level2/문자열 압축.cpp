#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(string s) {
    
    int len = s.length();
    int answer = len;  
    
    string ansStr="";
    
    int i,j;
    string str1,str2;
    int cnt;
    
    for(i=1; i<=len/2; i++){
        
       // if(len%i !=0) continue;
        
        cnt =1;
        str1 = s.substr(0,i);
        ansStr="";
        
        for(j=i; j<len; j+=i){
            
            str2 =s.substr(j,i);      
            if(str1.compare(str2)==0){
                cnt++;
            }
            else {
                if(cnt>1){ ansStr += (to_string(cnt))+str1;}
                else{ansStr += str1;}              
                str1 = str2;            
                cnt=1;
                }
            }
        
            if(cnt>1){ ansStr += (to_string(cnt))+str1;}
            else{ansStr += str1;}    
        
        
       // cout << cnt << ' ' <<  ansStr << '\n';
        int tmpLen = ansStr.length(); 
        answer=min(answer,tmpLen);        
        }
        

    return answer;
}
#include <iostream>
#include <string>
#include <stack>
using namespace std;

int solution(string s)
{
   stack<char> chStack;
    int i,len=s.length();
    
    for(i=0;i<len;i++){
        
        if(!chStack.empty() && chStack.top() == s[i]){
            chStack.pop();
        }else{
            chStack.push(s[i]);
        }
        
    }
    
    return chStack.empty();   
}

/*
 int preLen=0,i;
    
    for(; preLen!=s.length() && s.length()>0;){ 
        preLen=s.length();
        for(i=0; i<s.length()-1; i++){
            if(s[i] == s[i+1]){
                s.replace(i,2,"");
                break;
            }
        }
    }
    

    return s.empty()?1:0;
*/
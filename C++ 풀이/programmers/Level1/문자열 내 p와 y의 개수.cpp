#include <string>
#include <iostream>
using namespace std;

bool solution(string s)
{

    int len=s.length();
    int i;
    int pLen=0,yLen=0;
    
    for(i=0; i<len; i++){
        if(s[i] =='p' || s[i] == 'P') pLen++;
        else if(s[i] =='y' || s[i] == 'Y') yLen++;
    }
    
    

    return pLen==yLen ? 1:0;
}
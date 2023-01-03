#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(string s) {
    vector<int> answer(2,0);
    
    int i;
    string tmp;
    
    for(;s.length()>1;){
        
        answer[0]++;
        
        tmp="";   
        for(auto ch : s){
            if(ch=='1'){tmp += ch;}
        }
        
        answer[1] += s.length() - tmp.length(); 
        
        int len = tmp.length();
        tmp="";        
        
        for(;len>0;){
            tmp+= (len%2) + '0';
            len/=2;
        }
        
        reverse(tmp.begin(),tmp.end());
        s = tmp;
        
    }
    
    
    
    return answer;
}
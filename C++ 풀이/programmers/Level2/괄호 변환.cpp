#include <string>
#include <vector>

using namespace std;

int partition(string p){
    int open=0,close=0;
    int len = p.length();
    int i;
    
    for(i=0; i<len; i++){
        
        if(p[i] == '(') open++;
        else close++;
       
        if(open==close){return i+1;}        
    }
    
}

bool isRight(string p){
    
    vector<char> stackCh;
    
    for(auto ch : p){
        if(ch=='(') stackCh.push_back('(');
        else if(!stackCh.empty() && stackCh.back() == '(') stackCh.pop_back();
    }
    
    return stackCh.empty();
    
}


string solution(string p) {
    if(p.empty()) return "";
    
    int point = partition(p);
    
    string u,v;
    u= p.substr(0,point); 
    v= p.substr(point); 
    
    if(isRight(u)){
        return u+solution(v);
    }
    else{
        
        u = u.substr(1,u.length()-2);
        
        for(int i=0; i<u.length(); i++){
            u[i] = (u[i] == '(' ? ')' : '(');
        }
        
        return '(' + solution(v) + ')' + u;
    }
    
    
}
#include <string>
#include <vector>
#include <unordered_map>
#include <iostream>

using namespace std;

vector<int> solution(string msg) {

    unordered_map<string,int> LZW;
    string s;
    int idx;
    
    for(idx=1; idx<=26; idx++){
        s="",s+= (char)(idx+64);
        LZW[s] = idx;
    }
    
    int i,pos,size,msgLen= msg.length();
    int pushNum;
    
    vector<int> answer;
    
    for(i=0; i<msgLen; i++){
        size = 1;
        
        for(;i+size-1<msgLen;){
            
            s = msg.substr(i,size);    
            
            if(!LZW[s]){
                answer.push_back(pushNum);   
                break;
            } 
            size++;
            pushNum = LZW[s];
        }
        
        i += (size-2);
        LZW[s] = idx++;             
    }
    
    answer.push_back(pushNum); 
    
    return answer;
}

/*
#include <string>
#include <vector>
#include <map>
using namespace std;

vector<int> solution(string msg) {
    vector<int> ans;
    map<string, int> mymap;
    string str = "";
    for(int i = 0; i < 26; ++i){
        str += (i+65);
        mymap[str.substr(i,1)] = i+1;
    }
    for(int i = 0; i < msg.size();){
        str = "";
        while(i < msg.size() && mymap.find(str + msg[i]) != mymap.end())
            str += msg[i++];
        ans.push_back(mymap[str]);
        if(i < msg.size()) mymap[str + msg[i]] = mymap.size() + 1;
    }
    return ans;
}

*/
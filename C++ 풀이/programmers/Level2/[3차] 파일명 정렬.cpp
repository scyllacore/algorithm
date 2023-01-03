#include <string>
#include <vector>
#include <cctype>
#include <algorithm>

using namespace std;

struct fileInfo{
    string name;   
    string head;
    int num;
    int idx;
};

bool cmp(const fileInfo& f1 , const fileInfo& f2){
    if(f1.head == f2.head){
        if(f1.num == f2.num){
           return  f1.idx <f2.idx;
        }else{
          return f1.num < f2.num; 
        }
    }
    else{
        return f1.head < f2.head;
    }
}

vector<string> solution(vector<string> files) {
    
    int i,idx=1;   
    vector<fileInfo> fileList;
    
     for(auto file : files){
        
        string tmp[2];
         
           for(i=0; i<file.length(); i++){    
            if(isdigit(file[i])){
                break;
           }
               
            tmp[0] += toupper(file[i]);      
        }
         
         for(; i<file.length(); i++){
            if(!isdigit(file[i])){
                break;
            }
            tmp[1] += file[i];      
        }        
      fileList.push_back({file,tmp[0],stoi(tmp[1]),idx++});           
     }
    
    
    sort(fileList.begin(),fileList.end(),cmp);
    
    vector<string> answer;
    
    for(auto file : fileList){
        answer.push_back(file.name);
    }
    
    return answer;
}


/*
#include <string>
#include <vector>
#include <cctype>
#include <iostream>
#include <algorithm>

using namespace std;

struct fileInfo{
    string name;   
    string head;
    int num;
    string tail;
    int idx; // 원래 순서를 유지해야 하는 조건이 있다면 순서도 저장해주자.
};

bool cmp(const fileInfo& f1 , const fileInfo& f2){
    if(f1.head == f2.head){
        if(f1.num == f2.num){
           return  f1.idx <f2.idx;
        }else{
          return f1.num < f2.num; 
        }
    }
    else{
        return f1.head < f2.head;
    }
}

vector<string> solution(vector<string> files) {
    
    int i,idx=1;   
    vector<fileInfo> fileList;
    
     for(auto file : files){
        
        string tmp[3];
         
           for(i=0; i<file.length(); i++){    
            if(isdigit(file[i])){
                break;
            }
               
            tmp[0] += toupper(file[i]);      
        }
         
         for(; i<file.length(); i++){
            if(!isdigit(file[i])){
                break;
            }
            tmp[1] += file[i];      
        } 
         
        
          for(; i<file.length(); i++){
            tmp[2] += toupper(file[i]);      
        } 
        
       
      cout << file << ' ' << tmp[0] << ' ' << stoi(tmp[1]) << ' ' << tmp[2] << '\n';            
      fileList.push_back({file,tmp[0],stoi(tmp[1]),tmp[2],idx++});  
         
     }
    
    
    sort(fileList.begin(),fileList.end(),cmp);
    
    vector<string> answer;
    
    for(auto file : fileList){
        answer.push_back(file.name);
    }
    
    return answer;
}
*/
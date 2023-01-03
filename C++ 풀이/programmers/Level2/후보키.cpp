#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <iostream>

using namespace std;

bool checkUnique(vector<vector<string>>& relation,vector<int>& combiKey){
    
    unordered_map<string,int> dataList;
    int i,j;
    string key;
    
    for(i=0; i<relation.size(); i++){      
        key="";       
        for(j=0; j<combiKey.size(); j++){ key += relation[i][combiKey[j]] + ' ';}   
        //{ key += relation[i][combiKey[j]];}  
        dataList[key] = 1;
    }
    
    if(relation.size() == dataList.size()) return 1;
    else return 0;
}

bool checkMinimal(vector<int>& candiKey,int key){
        
    for(auto iter : candiKey){
        if((iter & key) == iter) return 0;
        //"비트열B가 비트열A를 포함한다"는 다음 2가지 방법 1. (A|B)==B 2. (A&B)==A 으로 표현가능함
        
        /* if(find(candiKey.begin(),candiKey.end(),(iter & key)) != candiKey.end()) return 0;*/ 
    }
    return 1;
}

int solution(vector<vector<string>> relation) {
    
    vector<int> candiKey;
    
    int i,j;
    int size = relation[0].size();
    bool flag;
    
    for(i=1; i<(1<<size); i++){        
        vector<int> combiKey;  
        
        for(j=0; j<size; j++){  if(i&(1<<j)) combiKey.push_back(j);}
        if(checkUnique(relation,combiKey) && checkMinimal(candiKey,i)){ candiKey.push_back(i);}          
    }
    
    return candiKey.size();
        
}

/*
#include <string>
#include <vector>
#include <unordered_map>
#include <iostream>

using namespace std;

bool checkUnique(vector<vector<string>>& relation,vector<int>& keyCombi){
    
    unordered_map<string,int> dataList;
    int i,j;
    string key;
    
    for(i=0; i<relation.size(); i++){   
        
        key="";
        
        for(j=0; j<keyCombi.size(); j++){
            key += relation[i][j];
        }      
        dataList[key] = 1;
        cout << key << '\n';
    }
    
    if(relation.size() == dataList.size()) return 1;
    else return 0;
}

bool checkCandiKey(vector<int> candiKey,int key){
    
    int i;
    
    for(auto iter : candiKey){
        if(iter & key) return 0;
    }
    
    return 1;
}

int solution(vector<vector<string>> relation) {
    
    vector<int> candiKey;
    vector<int> keyCombi;
    
    int i,j;
    int size = relation[0].size();
    bool flag;
    
    for(i=1; i<(1<<size); i++){       
        flag = 1;
       
        for(j=0; j<size; j++){
            if(i&(1<<j)) keyCombi.push_back(j);
        }
                
        if(!checkUnique(relation,keyCombi)){flag=0;} 
        
        if(flag && checkCandiKey(candiKey,i)){
                cout << i << '\n';
                candiKey.push_back(i);
        }   
        
        keyCombi.clear();
        
    }
    
    return candiKey.size();
        
}

2.#include <string>
#include <vector>
#include <unordered_map>
#include <iostream>

using namespace std;

bool checkUnique(vector<vector<string>>& relation,vector<int>& combiKey){
    
    unordered_map<string,int> dataList;
    int i,j;
    string key;
    
    for(i=0; i<relation.size(); i++){      
        key="";
        
        for(j=0; j<combiKey.size(); j++){
            key += relation[i][combiKey[j]];
        }      
        dataList[key] = 1;
        //cout << key << '\n';
    }
    
    if(relation.size() == dataList.size()) return 1;
    else return 0;
}

bool checkCandiKey(vector<int> candiKey,int key){
    
    int i;
    
    for(auto iter : candiKey){
        if(iter & key) return 0;
    }
    
    return 1;
}

int solution(vector<vector<string>> relation) {
    
    vector<int> candiKey;
    vector<int> combiKey;
    
    int i,j;
    int size = relation[0].size();
    bool flag;
    
    for(i=1; i<(1<<size); i++){       
       
        for(j=0; j<size; j++){
            if(i&(1<<j)) combiKey.push_back(j);
        }
        
        for(auto iter : combiKey){
            cout << iter << ' ';
        }cout << '\n';
        
        if(!checkUnique(relation,combiKey) && checkCandiKey(candiKey,i)){
              //  cout << i << '\n';
                candiKey.push_back(i);
        }   
        
        combiKey.clear();     
    }
    
    return candiKey.size();
        
}
*/
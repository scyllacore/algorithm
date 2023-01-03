#include <string>
#include <algorithm>
#include <cctype>
#include <unordered_map>

using namespace std;

unordered_map<string,int> findSet(string s){
    
    unordered_map<string,int> um;    
    for(int i=0; i<s.length(); i++){
        if(isupper(s[i]) && isupper(s[i+1])){
            um[s.substr(i,2)]++;
        }
    }
    
    return um;
    
}

int solution(string str1, string str2) {
    int answer = 0;
 
    transform(str1.begin(),str1.end(),str1.begin(), ::toupper);
    transform(str2.begin(),str2.end(),str2.begin(), ::toupper);
       
    unordered_map<string,int> hash1,hash2;       
    hash1=findSet(str1),hash2=findSet(str2);

    int uni=0,inter=0;
        
    for(auto iter : hash1){
        inter += min(iter.second,hash2[iter.first]);      
    }
    
    for(auto iter : hash2){
        hash1[iter.first] = max(iter.second,hash1[iter.first]);      
    }
      
    for(auto iter : hash1){
        uni += max(iter.second,hash2[iter.first]);      
    }
    
    
    if(uni==0) return 65536;
    return (double)inter/uni* 65536;
}

/*
#include <string>
#include <algorithm>
#include <cctype>
#include <unordered_map>

using namespace std;

unordered_map<string,int> findSet(string s){
    
    unordered_map<string,int> um;    
    for(int i=0; i<s.length(); i++){
        if(isupper(s[i]) && isupper(s[i+1])){
            um[s.substr(i,2)]++;
        }
    }
    
    return um;
    
}

int solution(string str1, string str2) {
    int answer = 0;
 
    transform(str1.begin(),str1.end(),str1.begin(), ::toupper);
    transform(str2.begin(),str2.end(),str2.begin(), ::toupper);
       
    unordered_map<string,int> cnt1,cnt2;       
    cnt1=findSet(str1),cnt2=findSet(str2);

    int uni=0,inter=0;
        
    for(auto iter : cnt1){
        if(cnt2.find(iter.first) != cnt2.end()){    
        uni += max(iter.second,cnt2[iter.first]);
        inter += min(iter.second,cnt2[iter.first]); 
        cnt2[iter.first]= cnt1[iter.first]=0;      
        }        
    }
    
    for(auto iter:cnt1){uni += iter.second;}
    for(auto iter:cnt2){uni += iter.second;}
    
    if(uni==0) return 65536;
    return (double)inter/uni* 65536;
}
*/
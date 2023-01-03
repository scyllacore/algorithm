#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

bool solution(vector<string> phone_book) {
    
    int i,j;
    unordered_map<string,bool> hashMap; 
    
    
    for(i=0; i<phone_book.size(); i++){
        hashMap[phone_book[i]] = 1;
    }
    
    string numTmp;
    
    for(i=0; i<phone_book.size(); i++){
        numTmp = "";
        for(j=0; j<phone_book[i].size()-1; j++){ //j<phone_book[i].size()
            numTmp += phone_book[i][j];    
            if(hashMap[numTmp]){return 0;}  // if(hashMap[numTmp] && numTmp != phone_book[i])
        }      
    }
    // 접두사를 다른 전화번호로 부터 찾을 때를 생각해야 한다.
    // 접두사를 자기 자신으로 부터 찾으면 안된다.
    
    return 1;
}

/*
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool solution(vector<string> phone_book) {
    
    sort(phone_book.begin(),phone_book.end());
    
    for(int i=0; i<phone_book.size()-1; i++){
        if(phone_book[i].compare(phone_book[i+1].substr(0,phone_book[i].size())) == 0){return 0;}       
    }
    
    return 1;
*/
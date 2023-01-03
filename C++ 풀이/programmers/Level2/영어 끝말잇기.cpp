#include <string>
#include <vector>
#include <unordered_map>
#include <iostream>

using namespace std;

vector<int> solution(int n, vector<string> words) {
    
    unordered_map<string,bool> uniqueWord;
    uniqueWord[words[0]] = 1;
    
    for(int i=1; i<words.size(); i++){
        if(words[i-1][words[i-1].length()-1] == words[i][0] && !uniqueWord[words[i]]){
            uniqueWord[words[i]] = 1;
        }
        else{
            return vector<int>{i%n+1,i/n+1}; 
        }
        
    }
    
    return vector<int>{0,0}; 
}
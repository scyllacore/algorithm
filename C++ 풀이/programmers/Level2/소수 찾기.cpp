#include <string>
#include <vector>
#include <iostream>
#include <unordered_map>

using namespace std;

#define MAX_SIZE 10000001

bool prime[MAX_SIZE];
bool visited[7];
unordered_map<int,int> primeList;

string number,combiNum;
int maxDepth;

void eratos(){
    
    int i,j;
    
    for(i=2; i<=MAX_SIZE/i; i++){
        
        if(prime[i] == 0){
            for(j=i*i; j<MAX_SIZE; j+=i){
                prime[j] = 1;
            }
        }     
    }   
    
}

void DFS_btrk(int depth){
    
    if(depth >= maxDepth){
        
        int cN = stoi(combiNum);
        
        if(!prime[cN]){
            primeList[cN] = 1;
        }
        
        return;
    }
    
    for(int i=0; i<number.length(); i++){
        
        if(!visited[i]){    
            visited[i]=1;
            combiNum.push_back(number[i]);
            
            DFS_btrk(depth+1);
            
            visited[i]=0;
            combiNum.pop_back();
        }
        
    }
    
}

int solution(string numbers) {
    
    
    fill_n(prime,MAX_SIZE,0);
    fill_n(visited,7,0);
    prime[0] = prime[1] = 1;
    
    eratos();  
    
    number = numbers;
    combiNum="";
    
    for(int i=1; i<=number.length(); i++){
    maxDepth = i;
    DFS_btrk(0);
    }
    
    int answer=0;
    
    for(auto iter : primeList){
        answer += iter.second;
    }
    
    return answer;
       
}
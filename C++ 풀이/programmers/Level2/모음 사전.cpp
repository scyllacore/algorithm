#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

int answer,cnt;
string word,alpha="AEIOU";

void DFS(int depth,string tmp){
    //cnt++; 불필요한 접근이 있을 수 있으니 이 구간에서 cnt를 증가 시켜주지 않는다
    if(tmp == word){ // 접근하고 처음에 바로 확인한다. for문 안에서 확인하는 것은 피해준다.
        answer = cnt;
        return;
    }
    
    //cnt++; 여기도 가능
    
    if(depth>4){return;}
    
    for(int i=0; i<5; i++){
        cnt++; // 다음 단어로 접근 할때만 cnt 증가 시켜줌.
        DFS(depth+1,tmp+alpha[i]);
        
        // 한 번 거쳐간 단어가 중간에 거쳐가는 경로가 될 수는 있지만 이에대해 cnt를 다시 증가 시키지 않는다.
    }
    
}

int solution(string w) {
    word = w;
    cnt = 0;
    DFS(0,"");
    
    return answer;
}

/*
#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

int cnt;
string alpha="AEIOU";

unordered_map<string,int> wordList;

void DFS(int depth,string tmp){
      
    if(depth>4){   
        if(!wordList[tmp])wordList[tmp] = cnt++;
        return;
    }

    int i;
    for(i=0; i<5; i++){
        if(!wordList[tmp])wordList[tmp] = cnt++;
        DFS(depth+1,tmp+alpha[i]);
    }
    
}

int solution(string word) {
    cnt = 1;
    
    DFS(0,"");
    
    return wordList[word]-1;
}
*/
#include <string>
#include <vector>
#include <unordered_map>
#include <cmath>

using namespace std;

unordered_map<char,int> friendsMap; //  = { {'A',0},{'B,0'}...} 가능
vector<string> Data;

int answer;

char friendsCh[8]= {'A', 'C', 'F', 'J', 'M', 'N', 'R', 'T'};
char friendsCombi[8];
bool visited[8];

void DFS(int depth){
    
    int i;
    
    if(depth>7){
        
        int front,back;
        int dis;
        
        for(string str:Data){
            front = friendsMap[str[0]];
            back = friendsMap[str[2]];
            
            dis = abs(front-back);
            
            if(str[3] == '=' && dis!= (str[4]-'0'+1)){
                return;
            }
            else if(str[3] == '>' && dis <= (str[4]-'0'+1)){
                return;
            }
            else if(str[3] == '<' && dis >= (str[4]-'0'+1)){
                return;
            }
                       
        }
        
        answer++;
        return;
        
    }
    
    for(i=0; i<8; i++){
        if(!visited[i]){
            visited[i]= 1;
    
            friendsCombi[depth] = friendsCh[i];
            friendsMap[friendsCh[i]] =depth;
            
            DFS(depth+1);
            
            visited[i]= 0;
        }
    }    
    
}

// 전역 변수를 정의할 경우 함수 내에 초기화 코드를 꼭 작성해주세요.
int solution(int n, vector<string> d) {
    
    Data = d;
    answer=0;
    fill(&visited[0],&visited[8],0);
    
    friendsMap.insert({'A',0}); // friendsMap['A'] = 0;
    friendsMap.insert({'C',0});
    friendsMap.insert({'F',0});
    friendsMap.insert({'J',0});
    friendsMap.insert({'M',0});
    friendsMap.insert({'N',0});
    friendsMap.insert({'R',0});
    friendsMap.insert({'T',0});
    
       
    DFS(0); 
    return answer;
}
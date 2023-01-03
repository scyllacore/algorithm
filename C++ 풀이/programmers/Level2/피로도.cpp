#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool visited[5001];
int answer;

void DFS_btrk(int move,int stamina,vector<vector<int>>& dun){
    
    answer = max(move,answer);
    
    int mapSize = dun.size();
    
    if(move >= mapSize){return;}
    
    for(int i=0; i<mapSize; i++){
       if(!visited[i] && stamina>= dun[i][0]){
           visited[i] = 1;
           DFS_btrk(move+1,stamina-dun[i][1],dun);
           visited[i] = 0;
       } 
    }
       
}

int solution(int k, vector<vector<int>> dungeons) {
    
    fill_n(visited,5001,0);
    answer=0;
    
    DFS_btrk(0,k,dungeons);
    
    return answer;
}
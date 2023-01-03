#include<vector>
#include <iostream>
#include <queue>

using namespace std;

int dy[]={-1,1,0,0};
int dx[]={0,0,-1,1};
bool visited[100][100];

struct pos{
    int y,x;
};


int BFS(vector<vector<int>>& mapNM){
    
    queue<pos> bfsQ;
    bfsQ.push({0,0});
    visited[0][0] = 1;
       
    int curY,curX;
    int nextY,nextX;
    int i;
    int n = mapNM.size()-1 , m = mapNM[0].size()-1;
    
    while(!bfsQ.empty()){
        
        curY = bfsQ.front().y;
        curX = bfsQ.front().x;
        bfsQ.pop();
        
        if(curY == n && curX == m){
            return mapNM[curY][curX];
        }
        
        for(i=0; i<4; i++){
            nextY= curY + dy[i];
            nextX= curX + dx[i];
            
            if(nextY<0 || nextY >n || nextX<0 || nextX >m) continue;
            
            if(mapNM[nextY][nextX] && !visited[nextY][nextX]){
                visited[nextY][nextX] = 1;
                mapNM[nextY][nextX] = mapNM[curY][curX] + 1;
                bfsQ.push({nextY,nextX});
            }                   
        }      
    }
    
    return -1;   
}

int solution(vector<vector<int>> maps)
{
    vector<vector<int>> mapNM(maps);
    
    fill(&visited[0][0],&visited[99][100],0);
    
    return BFS(mapNM);
}


/*
vector<vector<int>> graph;
graph.assign(5, vector<int>(5, 1));

// 위의 벡터를 복사하려면...

vector<vector<int>> newGraph;
newGraph.assign(graph.size(), vector<int>(graph.size());
copy(graph.begin(), graph.end(), newGraph.begin());
*/
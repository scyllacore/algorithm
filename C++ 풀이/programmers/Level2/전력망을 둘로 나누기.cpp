#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <iostream>

using namespace std;

vector<vector<int>> graph;

int BFS(int v1,int v2){
    bool visited[101] = {0};  
    queue<int> bfsQ;
    
    bfsQ.push(v1);
    visited[v1] = visited[v2] = 1;
    
    int curV,nextV;
    int i,cnt=0;
    
    while(!bfsQ.empty()){
        curV = bfsQ.front();
        cnt++;
        bfsQ.pop();
        
        for(i=0; i<graph[curV].size(); i++){
            
            nextV = graph[curV][i];
            
            if(!visited[nextV]){
                 visited[nextV] = 1;
                 bfsQ.push(nextV);
            }
        }      
    }
       
    return cnt;
}

int solution(int n, vector<vector<int>> wires) {
    
    graph.assign(n+1,vector<int>(0));
    
    int i;
    
    for(auto& wire : wires){
        graph[wire[0]].push_back(wire[1]);
        graph[wire[1]].push_back(wire[0]);       
    }
    
    int answer = 100;
    
    for(auto& wire : wires){
        int cnt1 = BFS(wire[0],wire[1]);
        int cnt2 = BFS(wire[1],wire[0]);
        answer = min(abs(cnt1-cnt2),answer);
    }
        
    return answer;
}
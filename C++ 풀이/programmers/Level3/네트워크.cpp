#include <string>
#include <vector>
#include <queue>

using namespace std;

vector<vector<int>> graph;
bool visited[201]={0};

void BFS(int node){
    
    queue<int> bfsQ;
    bfsQ.push(node);
    visited[node]=1;
    
    int curNode,nextNode;
    
    while(!bfsQ.empty()){
        curNode = bfsQ.front();
        bfsQ.pop();
        
        for(int i=0; i<graph[curNode].size(); i++){
            nextNode = graph[curNode][i];        
            if(!visited[nextNode]) {
                visited[nextNode] = 1;
                bfsQ.push(nextNode);   
            }
        }   
    }   
    
}

int solution(int n, vector<vector<int>> computers) {
    
    graph.assign(n+1,vector<int>(0));  
    int i,j;
    
    for(i=0; i<n; i++){
        for(j=0; j<n; j++){
            if(i!=j && computers[i][j]) graph[i+1].push_back(j+1);
        }
    }
     
    int answer = 0;
    
    for(i=1; i<=n; i++){
        if(!visited[i]) {
            BFS(i);
            answer++;
        }
    } 
    

    return answer;
}
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

bool visited[100][100];
int m,n;

struct pos{
    int y,x;
};

int dy[] ={-1,1,0,0};
int dx[] ={0,0,-1,1};



int BFS(int y,int x,vector<vector<int>>& picture){
    
    queue<pos> bfsQ;
    
    visited[y][x]=1;
    bfsQ.push({y,x});
    
    int curY,curX,curColor=picture[y][x];
    int nextY,nextX;
    int i;
    
    int cnt=1;
    
    while(!bfsQ.empty()){
        
        curY = bfsQ.front().y;
        curX = bfsQ.front().x;
        bfsQ.pop();
        
        for(i=0; i<4; i++){
            nextY= curY+dy[i];
            nextX= curX+dx[i];
            
            if(nextY<0 ||nextY>=m || nextX<0 || nextX>=n){continue;}
            
            if(!visited[nextY][nextX] && picture[nextY][nextX] == curColor){
                visited[nextY][nextX]=1;
                bfsQ.push({nextY,nextX});
                cnt++;
            }         
        }
        
    }
    
    return cnt;
    
}


// 전역 변수를 정의할 경우 함수 내에 초기화 코드를 꼭 작성해주세요.
vector<int> solution(int M, int N, vector<vector<int>> picture) {  
  
    m=M,n=N;
    fill(&visited[0][0],&visited[99][100],0);
    
    int i,j;
    
    int number_of_area = 0;
    int max_size_of_one_area = 0;
    int area;
    
    for(i=0; i<m; i++){
        for(j=0; j<n; j++){
        if(!visited[i][j] && picture[i][j]){
             area=BFS(i,j,picture);   
             number_of_area++;
             max_size_of_one_area = max(area,max_size_of_one_area);
          }
        }
    }
    
   
    vector<int> answer(2);
    answer[0] = number_of_area;
    answer[1] = max_size_of_one_area;
    return answer;
}
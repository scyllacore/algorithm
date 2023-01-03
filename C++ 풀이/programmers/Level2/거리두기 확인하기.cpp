#include <string>
#include <vector>
#include <queue>

using namespace std;

int map55[5][5];

int dy[] ={-1,1,0,0};
int dx[] ={0,0,-1,1};

struct pos{
    int y,x,move;
};


bool BFS(){
    
    int i,j;
    queue<pos> bfsQ;
    
    for(i=0; i<5; i++){
        for(j=0; j<5; j++){
            if(map55[i][j] == 1){bfsQ.push({i,j,0});}
        }
    }
    
    int curY,curX,move;
    int nextY,nextX;
    
    while(!bfsQ.empty()){
        
        curY = bfsQ.front().y;
        curX = bfsQ.front().x;
        move = bfsQ.front().move;
        bfsQ.pop();
        
        if(move >=1) continue;
        
        for(i=0; i<4; i++){
            nextY = curY + dy[i];
            nextX = curX + dx[i];
            
            if(nextY<0 || nextY>=5 || nextX<0 || nextX>=5){continue;}
            
            if(map55[nextY][nextX] == 1){return 0;} // if(map55[nextY][nextX] == 1 && move == 0)
            
            if(!map55[nextY][nextX]){
                map55[nextY][nextX] = 1;
                bfsQ.push({nextY,nextX,move+1});
            }                 
        }       
    }
    
    return 1;
            
}

vector<int> solution(vector<vector<string>> places) {
    
    int place;
    int i,j;
    
    vector<int> answer;
    
    for(place=0; place<5; place++){
    
        for(i=0; i<5; i++){
            for(j=0; j<5; j++){
                if(places[place][i][j] =='P') map55[i][j] = 1;
                else if(places[place][i][j] =='O') map55[i][j] = 0;
                else if(places[place][i][j] =='X') map55[i][j] = -1;                      
            }
        }
    
        int res = BFS();
        answer.push_back(res);
    }
    
    return answer;
}
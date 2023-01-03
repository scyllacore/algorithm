#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

vector<vector<int>> board;

int cycle(int y1,int x1,int y2,int x2){
    
    queue<int> q;
    int i;
    
    int minVal = board[y1+1][x1];  
    q.push(board[y1+1][x1]);
    
    for(i=x1; i<=x2; i++){
        minVal = min(board[y1][i],minVal);
        q.push(board[y1][i]);
    }
    
    for(i=y1+1; i<=y2; i++){
        minVal = min(board[i][x2],minVal);
        q.push(board[i][x2]);
    }
    
    for(i=x2-1; i>=x1; i--){
        minVal = min(board[y2][i],minVal);
        q.push(board[y2][i]);
    }
    
    for(i=y2-1; i>=y1+2; i--){
        minVal = min(board[i][x1],minVal);
        q.push(board[i][x1]);
    }
    
    // 시계방향 회전
    
    for(i=x1; i<=x2; i++){
        board[y1][i] = q.front();
        q.pop();
    }
    
    for(i=y1+1; i<=y2; i++){
        board[i][x2]= q.front();
        q.pop();
    }
    
    for(i=x2-1; i>=x1; i--){
        board[y2][i]= q.front();
        q.pop();
    }
    
    for(i=y2-1; i>=y1+1; i--){
        board[i][x1]= q.front();
        q.pop();
    }
    
   return minVal;
    
    
}

vector<int> solution(int rows, int columns, vector<vector<int>> queries) {
    
    int size = queries.size();
    int i,j,minVal,n=1;
    vector<int> answer; 
    
    board.assign(rows,vector<int>(columns,0));
    
    for(i=0; i<rows; i++){
        for(j=0; j<columns; j++){
            board[i][j] = n++;
        }
    }
    
    for(i=0; i<size; i++){
       minVal=cycle(queries[i][0]-1,queries[i][1]-1,queries[i][2]-1,queries[i][3]-1);
        answer.push_back(minVal);
    }
    
      
    return answer;
}
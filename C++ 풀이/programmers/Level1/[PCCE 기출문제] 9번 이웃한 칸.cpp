#include <string>
#include <vector>
#include <queue>

using namespace std;

struct pos{
    int y,x;
};

int dy[] = {0,1,-1,0};
int dx[] = {1,0,0,-1};

int solution(vector<vector<string>> board, int h, int w) {
    int answer = 0;
    
    int n = board.size();
      
    for(int i=0; i<4; i++){
        int nY = h + dy[i];
        int nX = w + dx[i];
            
        if(nY < 0 || nY >= n || nX < 0 || nX >= n){
            continue;
        }
            
        if(board[nY][nX] == board[h][w]){
            answer++;
        } 
    }
    
    return answer;
}
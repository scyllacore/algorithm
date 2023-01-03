#include <string>
#include <stack>
#include <vector>

using namespace std;

int solution(vector<vector<int>> board, vector<int> moves) {
    
    //vector<stack<int>> vecStack(board.size());
    int size= board.size();
    
    vector<vector<int>> clawCrane(size);
    
    int i,j;
    
    for(j=0; j<size; j++){
        for(i=size-1; i>=0; i--){
            if(board[i][j] == 0){
                break;         
            }  
            clawCrane[j].push_back(board[i][j]);
        }
    }
    
    vector<int> basket;
    size = moves.size();
    int pullOut;
    
     int answer=0;
    
    for(i=0; i<size; i++){
        if(!clawCrane[moves[i]-1].empty()){
            pullOut = clawCrane[moves[i]-1].back();
            clawCrane[moves[i]-1].pop_back();
            
            if(!basket.empty() && pullOut == basket.back()){
                answer+=2;
                 basket.pop_back();
            }
            else{
                basket.push_back(pullOut);
            }     
        }
    }
    

    return answer;
}
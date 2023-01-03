#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

int solution(int m, int n, vector<string> b) {
    int i,j;
    vector<string> board;
    
     for(i=0; i<n; i++){
         board.push_back("");
          for(j=0; j<m; j++){
               board[i].push_back(b[m-1-j][i]);
          }
      } 

    unordered_map<int,bool> iconDelPos;    
    int answer = 0;
    
    do{  
      iconDelPos.clear(); 
      int rowSize = board.size()-1,colSize;  
        
      for(i=0; i<rowSize; i++){
          colSize = board[i].size()-1;
          for(j=0; j<colSize; j++){   
              if(j+1<board[i+1].size()){
                  if(board[i][j] == board[i][j+1] && board[i][j] == board[i+1][j] && board[i][j] == board[i+1][j+1]){
                      iconDelPos[i*30+j] = 1;
                      iconDelPos[i*30+(j+1)] = 1;
                      iconDelPos[(i+1)*30+j] = 1;
                      iconDelPos[(i+1)*30+(j+1)] = 1;             
                  }
              }
          }
      }  
             
      answer += iconDelPos.size();
      
      for(auto delPos : iconDelPos){
          board[delPos.first/30][delPos.first%30] = 'X'; 
      } 
        
      string tmp;
        
      rowSize = board.size();      
      for(i=0; i<rowSize; i++){
          tmp = "";
          colSize = board[i].size();
          for(j=0; j<colSize; j++){
              if(board[i][j] != 'X'){
                  tmp.push_back(board[i][j]);
              }
          }
        board[i] = tmp;
      }
        
        
    }while(!iconDelPos.empty());
    
    return answer;
}
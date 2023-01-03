#include <algorithm>
#include <vector>

using namespace std;

int solution(vector<vector<int>> board)
{
   int row = board.size(),col = board[0].size();       
   int answer=0; 
    
   vector<vector<int>> dp(row+1,vector<int>(col+1));
    
   int i,j; 
   for(i=1; i<=row; i++){
       for(j=1; j<=col; j++){
           dp[i][j] = board[i-1][j-1];
       }
   } 
    
   for(i=1; i<=row; i++){
       for(j=1; j<=col; j++){
           if(dp[i][j]){
              dp[i][j] = min(min(dp[i-1][j-1],dp[i-1][j]),dp[i][j-1])+1;
              answer = max(dp[i][j],answer);
           }
       }
   } 
    
    return answer*answer;
}
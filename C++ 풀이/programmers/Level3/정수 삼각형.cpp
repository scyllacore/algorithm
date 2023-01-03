#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int dp[501][501];

int solution(vector<vector<int>> triangle){
    
    fill(&dp[0][0],&dp[499][501],0);
    int size = triangle.size();
    
    int i,j;
    for(i=1; i<=size; i++){
        for(j=1; j<=i; j++){
            dp[i][j] = triangle[i-1][j-1];
        }
    }
    
     for(i=2; i<=size; i++){
        for(j=1; j<=i; j++){
          dp[i][j] = max(dp[i-1][j-1],dp[i-1][j])+dp[i][j];
        }
    }
    
         
    return *max_element(&dp[size][1],&dp[size][size+1]);
}
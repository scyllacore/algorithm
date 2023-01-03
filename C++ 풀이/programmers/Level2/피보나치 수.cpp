#include <string>
#include <vector>

using namespace std;

#define MOD 1234567

int dp[100001];

int solution(int n) {
    
    dp[0] = 0;
    dp[2] =dp[1] = 1;
    
    for(int i=3; i<=n; i++){
        dp[i] = (dp[i-1] + dp[i-2])% MOD;
    }    
    
    return dp[n];
}
#include <string>
#include <vector>

using namespace std;

#define MOD 1234567

long long solution(int n) {
   
    long long dp[2001] = {0,1,2};
    
    for(int i=3; i<=n; i++){
        dp[i] = (dp[i-1] + dp[i-2]) % MOD;
    }
    
    return dp[n];
    
}
#include <string>
#include <vector>

using namespace std;

#define MAX 60001
#define MOD (int)(1e9+7);

int dp[MAX] ={0};

int solution(int n) {
    
    dp[1] = 1;
    dp[2] = 2;
    
    for(int i=3; i<=n; i++){
        dp[i] = (dp[i-1] +dp[i-2]) % MOD;
    }
    
    return dp[n];
    
    
}
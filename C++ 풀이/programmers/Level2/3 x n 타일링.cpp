#include <string>
#include <vector>

using namespace std;

#define MOD (int)(1e9+7)

int solution(int n) {
    int i,j;
	long long dp[5000] = { 1,0,3,0 };

	for (i = 4; i <= n; i++) {
		dp[i] = 3 * dp[i-2];

		for (j = 4; j <= i; j += 2) {
			dp[i] += 2 * dp[i - j];
		}
        
        dp[i] %= MOD;
	}

	return dp[n];
}
#include <iostream>

using namespace std;

#define MOD (int)(1e9+9) // 괄호 묶어야함
#define MAX (int)1e6

unsigned long long dp[MAX+1] = {0,1,2,4};

int main() {

	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	int n, i, num;

	for (i = 4; i <= MAX; i++)
	{
		dp[i] = (dp[i - 1] + dp[i - 2] + dp[i - 3]) % MOD;
	}

	cin >> n;

	for (i = 0; i < n; i++)
	{
		cin >> num;
		cout << dp[num] << '\n';
	}

	return 0;


}
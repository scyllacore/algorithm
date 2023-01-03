#include <iostream>
#define MOD (int)1e9 // 나머지는 MOD로 정의해두기

using namespace std;

long long dp[201][201];

int main() {

	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	int N, K;
	int i, j;

	cin >> N >> K;

	for (i = 1; i <= 200; i++)
	{
		dp[i][1] = 1;
		dp[1][i] = i;
	}

	for (i = 2; i <= N; i++)
	{
		for (j = 2; j <= K; j++) {
			dp[i][j] = (dp[i - 1][j] + dp[i][j - 1])%MOD;
		}
	}

	cout << dp[N][K];

	return 0;
}

//자료형 큰거 쓰자 그냥.. 
//자료형 잘못써도 오답 처리 된다 . int -> long long으로 바꿈
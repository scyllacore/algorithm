#include <iostream>
#define min(a,b) a<b?a:b

using namespace std;

int main() {

	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	int n,i,j;
	cin >> n;

	int* dp = new int[n + 1];

	for (i = 0; i <= n; i++) {
		dp[i] = i;
	}


	for (i = 4; i <= n; i++){

		for (j = 1; j * j <= i; j++) {
			dp[i] = min(dp[i], dp[i - j * j]+1);
		}

	}

	cout << dp[n];


}


//43 
//36 4 1 1 1 -> 5번
//25 9 9 -> 3번
//(25 + 9) + 9 -> 43
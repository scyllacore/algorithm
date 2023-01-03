#include <iostream>
#include <algorithm>

using namespace std;

int dp[1001][1001] = { 0 };

int main() {

	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	string s1, s2;

	cin >> s1 >> s2;

	int i, j;
	int s1Len = s1.length(), s2Len = s2.length();

	for (i = 1; i <= s1Len; i++) {
		for (j = 1; j <= s2Len; j++) {
			if (s1[i - 1] == s2[j - 1])
			{
				dp[i][j] = dp[i - 1][j - 1] + 1;
			}
			else {
				dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
			}
		}
	}

	cout << dp[s1Len][s2Len];

	return 0;

}


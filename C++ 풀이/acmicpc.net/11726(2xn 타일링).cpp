#include <iostream>

using namespace std;

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);

    int n, i;

    cin >> n;

    int* dp = new int[n + 1];

    dp[1] = 1;
    dp[2] = 2;

    for (i = 3; i <= n; i++)
    {
        dp[i] = (dp[i - 2] + dp[i - 1]) % 10007;
    }

    cout << dp[n];


}
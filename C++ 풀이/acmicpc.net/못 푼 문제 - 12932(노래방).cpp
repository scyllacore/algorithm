#include <iostream>
#include <algorithm>

using namespace std;

#define MAX 2000
#define INF (long long)1e12;

int n;
long long num[MAX + 1];
long long dp[MAX + 1][MAX + 1];

long long go(int idx, int end) {
    if (idx > n) {
        return 0;
    }

    long long& ret = dp[idx][end];
    if (ret != -1) {
        return ret;
    }

    ret = INF;
    ret = min(ret, go(idx + 1, end) + ((idx == 1) ? 0 : abs(num[idx] - num[idx - 1])));
    ret = min(ret, go(idx + 1, idx - 1) + ((end == 0) ? 0 : abs(num[idx] - num[end])));

    return ret;
}

int main() {
    fill(&dp[0][0], &dp[MAX][MAX + 1], -1);

    cin >> n;

    for (int i = 1; i <= n; i++) {
        cin >> num[i];
    }

    cout << go(1, 0);

    return 0;
}

//https://glanceyes.com/entry/BOJ-%EB%B0%B1%EC%A4%80-11570%EB%B2%88-%ED%99%98%EC%83%81%EC%9D%98-%EB%93%80%EC%97%A3-1
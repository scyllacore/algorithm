#include<iostream>
#include <vector>

using namespace std;

#define SIZE 301

struct spotInfo {
    int duration;
    int count;
};

int n, m, k, t, a, b;
int curPeopleCnt[SIZE], dp[SIZE][SIZE];

vector<spotInfo> spot;

int cal(int cur, int count, int prev) {
    if (cur == spot.size()) { return 0; }
    if (dp[cur][count]) { return dp[cur][count]; }

    int cost = max(0, t - spot[cur].count);
    int real_cost = (prev >= cost) ? 0 : cost;

    int& ret = dp[cur][count];

    if (count - real_cost >= 0) {
        return ret = max(cal(cur + 1, count - real_cost, cost) + spot[cur].duration, cal(cur + 1, count, 0));
    }
    else return ret = cal(cur + 1, count, 0);
}
int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);

    cin >> n >> m >> k >> t;

    for (; m--;) {
        cin >> a >> b;

        for (int i = a; i < b; i++) {
            curPeopleCnt[i] = min(t, ++curPeopleCnt[i]);
        }

    }

    int count = curPeopleCnt[1];
    int duration = 1;

    for (int i = 2; i <= n; i++) {
        if (count != curPeopleCnt[i]) {
            spot.push_back({ duration,count });
            duration = 0;
            count = curPeopleCnt[i];
        }
        duration++;
    }

    spot.push_back({ duration,count });

    cout << cal(0, k, 0);
    return 0;
}

//https://blog.naver.com/jhc9639/221571006582
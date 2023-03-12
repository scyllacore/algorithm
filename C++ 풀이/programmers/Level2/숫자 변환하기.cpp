#include <string>
#include <vector>
#include <queue>

using namespace std;

#define MAX (int)1e6

int dp[MAX + 1] = { 0 };

int solution(int x, int y, int n) {

    queue<int> bfsQ;

    dp[y] = 1;
    bfsQ.push(y);

    for (; !bfsQ.empty();) {

        int cur = bfsQ.front();
        bfsQ.pop();

        if (cur - n > 0 && !dp[cur - n]) {
            dp[cur - n] = dp[cur] + 1;
            bfsQ.push(cur - n);
        }

        if (cur % 2 == 0 && cur / 2 > 0 && !dp[cur / 2]) {
            dp[cur / 2] = dp[cur] + 1;
            bfsQ.push(cur / 2);
        }

        if (cur % 3 == 0 && cur / 3 > 0 && !dp[cur / 3]) {
            dp[cur / 3] = dp[cur] + 1;
            bfsQ.push(cur / 3);
        }

    }

    return dp[x] == 0 ? -1 : dp[x] - 1;

}
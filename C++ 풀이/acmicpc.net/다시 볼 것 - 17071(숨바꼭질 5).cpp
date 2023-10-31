#include <iostream>
#include <queue>

using namespace std;

#define SIZE (int)5e5

int visited[2][SIZE + 1];
int n, k;

struct spotInfo {
    int curSpot;
    int curTime;
};

bool check(int spot) {
    if (spot < 0 || spot > SIZE) {
        return true;
    }
    return false;
}

int printRes() {

    for (int i = 0; i <= SIZE; i++) {
        int nextK = k + (i * (i + 1)) / 2;
        if (nextK > 500000) {
            return -1;
        }

        if (visited[i % 2][nextK] != -1 && visited[i % 2][nextK] <= i) {
            return i;
        }
    }

    return -1;
}

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);

    cin >> n >> k;

    queue<spotInfo> bfsQ;
    bfsQ.push({ n, 0 });

    visited[0][n] = 0;
    fill(&visited[0][0], &visited[1][SIZE + 1], -1);

    for (; !bfsQ.empty();) {

        int curSpot = bfsQ.front().curSpot;
        int curTime = bfsQ.front().curTime;
        bfsQ.pop();

        if (check(curSpot)) {
            continue;
        }
        if (visited[curTime % 2][curSpot] != -1) {
            continue;
        }

        visited[curTime % 2][curSpot] = curTime;

        bfsQ.push({ curSpot - 1, curTime + 1 });
        bfsQ.push({ curSpot + 1, curTime + 1 });
        bfsQ.push({ curSpot * 2, curTime + 1 });
    }

    cout << printRes();

    return 0;
}
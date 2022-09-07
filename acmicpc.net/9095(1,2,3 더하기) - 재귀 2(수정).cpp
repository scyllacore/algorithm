#include <iostream>
#include <algorithm>
using namespace std;

int n;

int calCnt(int sum) {
    if (sum > n) return 0;
    if (sum == n) return 1;
    int totalCnt = 0;
    for (int i = 1; i <= 3; i++) {
        totalCnt += calCnt(sum + i);
    }
    return totalCnt;
}

int main() {
    int tc;
    cin >> tc;

    while (tc--) {
        cin >> n;
        cout << calCnt(0) << '\n';
    }

    return 0;

}
#include <iostream>
#include <algorithm>
using namespace std;

int calSum(int sum, int ans) {
    if (sum > ans) return 0;
    if (sum == ans) return 1;
    int totalSum = 0;
    for (int i = 1; i <= 3; i++) {
        totalSum += calSum(sum + i, ans);
    }
    return totalSum;
}

int main() {
    int tc,ans;
    cin >> tc;

    while (tc--) {
        int n;
        cin >> n;
        ans = calSum(0, n);
        cout << ans << '\n';
    }

    return 0;

}
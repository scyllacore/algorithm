#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct idx {
    int idxVal;
    int idxPos;
};

bool cmp(const idx& i1, const idx& i2) {
    if (i1.idxVal == i2.idxVal) return i1.idxPos < i2.idxPos;
    else return i1.idxVal < i2.idxVal;
}

int main(void)

{
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(NULL);

    int N,i;
    cin >> N;

    vector<idx> arr(N);

    for (i = 0; i < N; i++)
    {
        cin >> arr[i].idxVal;
        arr[i].idxPos = i;
    }

    sort(arr.begin(), arr.end(),cmp);

    int ans = 0;

    for (i = 0; i < N; i++) {
        ans = max(ans, arr[i].idxPos - i);
    }

    cout << ans + 1;

    return 0;

}
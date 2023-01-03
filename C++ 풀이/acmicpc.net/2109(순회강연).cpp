#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

struct lecture {
    int p;
    int d;
};

bool cmp(const lecture& l1, const lecture& l2) {
    return l1.d < l2.d;
}

int main() {

    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);

    int n,res=0;
    priority_queue<int, vector<int>, greater<int>> pq;
    vector<lecture> lec;
    int p, d,i;

    cin >> n;
    for (i = 0; i < n; i++) {
        cin >> p >> d;
        lec.push_back({p,d});
    }

    sort(lec.begin(), lec.end(),cmp);

    for (int i = 0; i < n; i++) {
        pq.push(lec[i].p);
        res += lec[i].p;

        if (pq.size() > lec[i].d) {
            res -= pq.top();
            pq.pop();
        }
    }

    cout << res;

    return 0;
}

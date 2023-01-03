#include <iostream>
#include <set>

using namespace std;


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;
    while(t--) {
        multiset<int> ms;
        int k;
        cin >> k;
        while(k--) {
            char c;
            int x;
            cin >> c >> x;

            if(c == 'I') {
                ms.insert(x);
            }
            else if(c == 'D' && !ms.empty()) {
                if(x == 1)
                    ms.erase(--ms.end());
                else
                    ms.erase(ms.begin());
            }
        }
        if(!ms.empty()) {
            cout << *(--ms.end()) << ' ' << *ms.begin() << "\n";
        } else
            cout << "EMPTY" << "\n";

    }
    return 0;
}
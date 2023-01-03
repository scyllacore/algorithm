#include <cstdio>
#include <cstring>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
vector<int> v;
void go(int idx,vector<int> now) {
    if ( idx >= (int)v.size() ) return;
    if ( now.size() == 6 ) {
        for ( int i = 0 ; i < now.size() ; i++ )
            printf("%d ",now[i]);
        puts("");
    }
    for ( int i = idx ; i < v.size() && (int)now.size() < 6; i++ ) {
        now.push_back(v[i]);
        go(i+1,now);
        now.pop_back();
    }
}
int main() {
    bool first=true;
    for ( int n;scanf("%d",&n)==1 && n ; )  {
        if ( !first ) puts("");
        v.resize(n+1,0);
        for ( int i = 0 ; i < n ; i++ )
            scanf("%d",&v[i]);
        vector<int> ans;
        go(0,ans);
        first = false;
    }
    return 0;
}
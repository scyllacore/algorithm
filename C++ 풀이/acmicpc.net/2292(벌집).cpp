#include <iostream>

using namespace std;

int main()
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    
    int n;
    
    cin >> n;
    
    int sum=1,cnt=1;
    
    
    while(n>sum){
        sum += 6 * (cnt++);
    }
    
    cout << cnt;
    
    
    return 0;
    
    
}
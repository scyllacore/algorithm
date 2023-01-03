#include <iostream>

using namespace std;

int main(void) {
    
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);
    
    int a,b,i,j;
    cin >> a >> b;
    
    for(i=0; i<b; i++){
        for(j=0; j<a; j++){
            cout << '*';
        }
        cout << '\n';
    }
    
    return 0;
}
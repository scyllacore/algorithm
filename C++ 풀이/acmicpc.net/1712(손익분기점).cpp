#include <iostream> 

using namespace std;

int main()
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);
 
    int a,b,c;
    
    cin >> a >> b >> c;
    
    if(b>=c)
    {
        cout << -1;
    }
    else{
        cout << a/(c-b)+1;
    }
    
    
    return 0;
}


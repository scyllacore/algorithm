#include <iostream>

using namespace std;

int main()
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);
   
    int num,i,a,b;
    
    
    cin >> num;
    
    for(i=0; i<num; i++)
    {
        cin >> a >> b;
        cout << a+b << '\n';
    }
    
    return 0;
}
#include <iostream>

using namespace std;

int main()
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    
    int arr[15][14]={{1,2,3,4,5,6,7,8,9,10,11,12,13,14}},i,j;
    
    
    for(i=0; i<15; i++)
    {
        arr[i][0]= 1;
    }
    
    
    for(i=1; i<15; i++)
    {
        for(j=1; j<14; j++)
        {
            arr[i][j] = arr[i-1][j] + arr[i][j-1];
        }
    }
    
    int t,k,n;
    cin >> t;
    
    
    for(i=0; i<t; i++)
    {
        cin >> k >> n;
        cout << arr[k][n-1]<<'\n';
    }
    
    return 0;
    
}
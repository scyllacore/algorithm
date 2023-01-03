// Online C++ compiler to run C++ program online
#include <iostream>

using namespace std;

int main() {
    
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    
    int i;
    long arr[100] = {1,1,1,2,2};
    
    for(i=5; i<100; i++)
    {
        arr[i] = arr[i-1]+arr[i-5];
    }
    
    int n;
    cin >> n;
    
    for(i=0;i<n;i++){
    int tmp;
    cin >> tmp;
    cout << arr[tmp-1] << '\n';
    }
    

    return 0;
}
#include <iostream>
  
using namespace std;
  
int main()
{
    //cin.tie(NULL);
    //ios::sync_with_stdio(false);
  
    int n, i, j;
    unsigned long long cowSum=0;
    cin >> n;
  
    int* cowArr = new int[n];
  
    for (i = 0; i < n; i++)
    {
        cin >> cowArr[i];
    }
  
    for (i = 0; i < n - 1; i++)
    {
        for (j = i + 1; j < n; j++)
        {
            if (cowArr[i] <= cowArr[j])
                break;
  
          //  if (cowArr[i] > cowArr[j])
                cowSum++;
  
        }
    }
  
  
    cout << cowSum;
  
    delete[] cowArr;
  
  
  
}
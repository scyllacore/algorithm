#include <iostream>
#include <cstring>

using namespace std;

int main()
{
    int n,i,j,flag,cnt=0;
    
    cin >> n;
    
    char **str = new char*[n];
    
    for(i=0; i<n; i++)
    {
        str[i] = new char[101];
        cin >> str[i];
    }
    
    for(i=0; i<n; i++)
    {
        int alpha[26]= {0};
        
        flag =0;
        alpha[str[i][0]-97]++;
        
        for(j=1; str[i][j] != '\0'; j++){
            
            if(str[i][j-1] != str[i][j])
                alpha[str[i][j]-97]++;
            
        }
        
        for(j=0; j<26; j++){
            if(alpha[j] >1){
            flag = 1;
            break;
            }
        }
        
        //for(j=0; j<26; j++){
         //   cout <<alpha[j] << ' ';
        //}
        //cout << '\n';
        
        
        //cout << flag << '\n';
        if(flag == 0) cnt++;
        
        
    }
    
    
    cout << cnt;
    
    return 0;
    
}
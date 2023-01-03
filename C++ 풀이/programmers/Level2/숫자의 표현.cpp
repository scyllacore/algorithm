#include <algorithm>
#include <unordered_map>

using namespace std;


int solution(int n) {
    int answer=0, num=1, sum=0;
    while (true) {
        sum = 0;
        for (int i=1; i<=num; i++) {sum+=i;}
        if (sum > n){break;}
        if ((n - sum) % (num++)==0) {answer++;}
    }
    return answer;
}


/*
  for(i=1; i<=n; i++){
        cout << dp[i] << ' ';
}
 cout << start;
 int start = find(dp.begin(),dp.end(),n) - dp.begin();   
 
 1.
 
 int answer = 1;
    
    for(i=1; i<=n/2+1; i++){    
        for(j=1; dp[i]-dp[j] >= n; j++){
            if(dp[i]-dp[j] == n){
                cout << dp[i] << ' '<< dp[j] << '\n';
                answer++;
                break;
            }
        }    
    }
 
 
 2.
 
    int answer = 0;
    
    int start = lower_bound(dp.begin(),dp.begin()+n,n) - dp.begin();
    
    cout << start << '\n';
    
    for(i=1; i<=n; i++){    
        for(j=0; dp[i]-dp[j] >= n; j++){
            if(dp[i]-dp[j] == n){
                cout << dp[i] << ' '<< dp[j] << '\n';
                answer++;
                break;
            }
        }    
    }
    
    return answer;
 
 3.
  int dp[10001] ={0};
    unordered_map<int,int> idxMap;
    
    dp[1]=1;
    idxMap[0] = idxMap[1] = 1;
    
    int i,j;
    
    for(i=2; i<=n; i++){
        dp[i] = dp[i-1]+i;
        idxMap[dp[i]] = i;
    }
        
    int answer = 0;
    
    int start = lower_bound(dp,dp+n,n) - dp;
            
    for(i=start; i<=n; i++){
        if(idxMap[dp[i]-n]){
            answer++;
        } 
    }
    
    return answer;
 
 
 
*/
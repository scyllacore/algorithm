#include <string>
#include <vector>
#include <queue>
#include <numeric>

using namespace std;

int solution(vector<int> queue1, vector<int> queue2) {
    queue<long> q1;
    queue<long> q2;
    
    int loop= queue1.size();
    
    for(int i=0; i<loop; i++){
        q1.push(queue1[i]);
        q2.push(queue2[i]);
    }
    
    long sum1 = accumulate(queue1.begin(),queue1.end(),0);
    long sum2 = accumulate(queue2.begin(),queue2.end(),0);
    
    int ans=0;
    
    for(;ans<loop*3;ans++){
        
        if(sum1 == sum2){
            return ans;
        }
        
        if(sum1 > sum2){
            
            int tmp = q1.front();
            q1.pop();
            
            q2.push(tmp);
           
            
            sum1 -= tmp;
            sum2 += tmp;  
            
        }
        else{
            
            int tmp = q2.front();
            q2.pop();
            
            q1.push(tmp);
            
            sum2 -= tmp;
            sum1 += tmp;     
        }
             
    }
    
    return -1;
    
}
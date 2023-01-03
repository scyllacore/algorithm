#include <string>
#include <vector>
#include <queue>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    
    int size= progresses.size();    
    int cnt,i;
    
    queue<int> order;
    
    for(i=0; i<size; i++){
        order.push(i);
    }    
        
    vector<int> answer;
    
    while(!order.empty()){  
        cnt=0;
        
        for(i=0; i<size; i++){
            progresses[i] += speeds[i];
            
            if(!order.empty() && progresses[i]>=100 && i==order.front()){    //i<=order.front()
                //progresses[order.front()] = speeds[order.front()] =0;
                cnt++;
                order.pop();
            }
            
        }
        
        if(cnt!=0){
        answer.push_back(cnt);
        }
        
    }
    
    return answer;
}
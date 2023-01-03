#include <string>
#include <vector>
#include <queue>
#include <iostream>

using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights) {
    
    
    queue<int> bridge;
    for(int i=0; i<bridge_length-1; i++){
         bridge.push(0);
    }
    
    bridge.push(truck_weights[0]);  
    int wSum=truck_weights[0],idx=1,answer=1;
   
    while(!bridge.empty()){
        
        answer++;
        
        if(idx == truck_weights.size()){
            /*
            bridge.pop();
            continue;
            */
            
            answer+= bridge_length-1;
            break;
        }
        
        if(bridge.size()>=bridge_length){
            wSum-= bridge.front();
            bridge.pop();    
        }
               
        if(wSum+truck_weights[idx]<=weight){
            bridge.push(truck_weights[idx]);
            wSum+=truck_weights[idx++];
        }
        else{
           bridge.push(0);
        }
        
     }     
    
    return answer;
}
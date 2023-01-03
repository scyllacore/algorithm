#include <string>
#include <vector>
#include <queue>
#include <functional>

using namespace std;

int solution(vector<int> scoville, int K) {
    priority_queue<int,vector<int>,greater<>> pq(scoville.begin(),scoville.end());
    
    /*
    for(int val :scoville){
        pq.push(val);
    }
    */
     
    int answer = 0;
    int min1,min2;
    
    while(pq.size()>=2 && pq.top()<K){
        min1 = pq.top(),pq.pop();
        min2 = 2*pq.top(),pq.pop();
        pq.push(min1+min2);
        answer++;
    }
    
    if(pq.top() < K){
        answer=-1;
    }
    
    return answer;
}
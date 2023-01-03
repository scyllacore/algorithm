#include <vector>
#include <queue>

using namespace std;

struct paper{
    int prior;
    int idx;
};

int solution(vector<int> priorities, int location) {
    
    int priorLevel[10] = {0};
    int i,order=1;
    
    queue<paper> q;
    
    
    for(i=0; i<priorities.size(); i++){
        priorLevel[priorities[i]]++;
        q.push({priorities[i],i});
    }
    
    for(i=9; i>=1; i--){
        for(;priorLevel[i]>0;){
            if(i==q.front().prior){
                
                if(q.front().idx == location){ return order;}     
                
                priorLevel[i]--;
                order++;
                q.pop();
            }
            else{
                q.push(q.front());
                q.pop();
            }
        }
    }
       
    
}